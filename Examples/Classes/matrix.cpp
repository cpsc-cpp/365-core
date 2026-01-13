#include "matrix.h"
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <iostream>

using namespace std;

// copy constructor
Matrix::Matrix(const Matrix& m) 
    : dim{m.dim}, elem{new double[m.size()]} {
        // perform a copy
        copy(m.elem, m.elem+m.size(), elem);
        cout << "Copy constructor called" << endl;
}

// copy assignment
Matrix& Matrix::operator=(const Matrix& m) {
    // require matrices to have same dimension
    if(dim[0] != m.dim[0] || dim[1] != m.dim[1]) {
        throw runtime_error("Size mismatch in Matrix =");
    }
    copy(m.elem, m.elem+m.size(), elem);
    cout << "Copy assignment called" << endl;
    return *this;
}

// move constructor
Matrix::Matrix(Matrix&& m) 
    : dim{m.dim}, elem{m.elem} // steal m's array
{
    // clean up m
    m.dim = {0,0};
    m.elem = nullptr;
    cout << "Move constructor called" << endl;
}

// move assignment
Matrix& Matrix::operator=(Matrix&& m) {
    // can make use of std::swap
    swap(dim, m.dim); 
    swap(elem, m.elem); // swaps pointers effectively stealing m's array
    
    cout << "Move assignment called" << endl;
    return *this;
}

// return string representation of matrix
string Matrix::to_string() const {
    stringstream str;
    str << "{";
    for(int i = 0; i < dim[0]; i++) {
        str << "{";
        for(int j = 0; j < dim[1]; j++) {
            str << elem[i*dim[1]+j];
            if (j!=dim[1]-1) str << ", ";
        }
        if (i != dim[0]-1) 
            str << "}, ";
        else
            str << "}";
    }
    str << "}";
    return str.str();

}



// A function to add two matrices element-wise
Matrix operator+(const Matrix& a, const Matrix& b) {
    if( a.dim[0] != b.dim[0] || a.dim[1] != b.dim[1] ) {
        throw runtime_error("Size mismatch in Matrix +");
    }

    // avoid heap allocation
    Matrix result {a.dim[0], a.dim[1]};
    for(int i = 0; i < a.size(); i++ ) {
        result.elem[i] = a.elem[i] + b.elem[i];
    }
    return result;
}

int main() {
    Matrix A{3,3}; // constructor
    Matrix B{A};  // copy constructor
    //B = A;
    
    Matrix C {3,3}; 
    C = A + B;
    
    cout << C.to_string() << endl << endl;

    Matrix D{ std::move(C) }; // C is in moved-from state
    cout << C.to_string() << endl;
}