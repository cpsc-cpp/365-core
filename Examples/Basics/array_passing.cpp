/**
 * @file array_passing.cpp
 * @brief Passing arrays to functions 
 *  
 * Passing around 1D and 2D arrays
 * 
 */

#include <iostream>
#include <cstring>

using namespace std;

// Function definitions
void print_array( int arr[], size_t N);
void print_array_2d( int* arr[], size_t dim1, size_t dim2);

int main() {

    // 1D arrays

    int arr[] {0, 1, 2, 3, 4};
    print_array(arr, 5);
    cout << endl; 
    // we are actually passing a pointer to the first element
    print_array(&arr[0], 5); 
    cout << endl;

    // Recall that 2D static arrays are infact 1D arrays

    int mat[3][4] {{0, 1, 2, 3},{4, 5, 6, 7},{8, 9, 10, 11}};
    print_array(&mat[0][0], 12); // loses 2D information

    // Passing dynamically allocated 2D arrays

    int** darr2 = new int*[3]; // for 3 rows
    for(size_t i = 0; i < 3; i++) {
        darr2[i] = new int[4]; // 4 columns
    }

    size_t cnt = 0;
    cout << "{";
    for(size_t r = 0; r < 3; r++) {
        for(size_t c = 0; c < 4; c++) {
            darr2[r][c] = cnt++;
            cout << darr2[r][c] << ", ";
        }
    }
    cout << "}" << endl;
    
    cout << endl;
    print_array_2d( darr2, 3, 4);
    cout << endl;

    for(size_t r = 0; r < 3; r++) {
        delete[] darr2[r];
    }
    darr2 = nullptr;

    return 0;
}

void print_array(int arr[], size_t N ) {
    cout << "{";
    for(size_t i = 0; i < N; i++ ) {
        cout << arr[i] << ", ";
    }
    cout << "}";
}

void print_array_2d( int* arr[], size_t dim1, size_t dim2 ) {
    cout << "{";
    for(size_t r = 0; r < dim1; r++ ) {
        cout << "{";
        for(size_t c = 0; c < dim2; c++ ) {
            cout << arr[r][c] << ", ";
        }
        cout << "}" << endl;
    }
    cout << "}";
}


