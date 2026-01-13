#include <cstdlib>
#include <array>
#include <string>

class Matrix {
    std::array<int, 2> dim;
    double* elem;

public:
    Matrix(int d1, int d2) : dim{d1,d2}, elem{new double[d1*d2]} {
        // initialize top-left square to identity
        for(int i = 0; i < dim[0]; i++) {
            for( int j = 0; j < dim[1]; j++ ) {
                if( i == j) {
                    elem[i*dim[1]+j] = 1.0;
                } else {
                    elem[i*dim[1]+j] = 0.0;
                } 
            }
        }
    }

    int size() const {
        return dim[0]*dim[1];
    }

    // copy constructor and assignment
    Matrix(const Matrix&);
    Matrix& operator=(const Matrix&);

    // move constructor and assignment
    Matrix(Matrix&&);
    Matrix& operator=(Matrix&&);

    // destructor
    ~Matrix() {delete[] elem;}

    // return a string representation of matrix
    std::string to_string() const;

    friend Matrix operator+(const Matrix& a, const Matrix& b);
};