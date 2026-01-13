/**
 * @file arrays.cpp
 * @brief Pointers and Arrays 
 * 
 * Working with pointers and arrays in C++.
 */

#include <iostream>
#include <cstring>

using namespace std;

int main() {

    // Let's explore C-style string literals first
    const char *str1 {"This is a string literal."};

    // Two ways to iterate through the characters:
    // 1. Familiar array syntax
    for(size_t i = 0; i < strlen(str1); i++) {
        cout << str1[i] << ' '; 
    }
    cout << endl;

    // 2. Use pointer arithmetic and check for null character
    for(const char *p = str1; *p != '\0'; ++p) {
        cout << *p << ' ' ;
    }
    cout << endl;

    // Statically allocated 1D and 2D arrays

    int arr[] {0, 1, 2, 3, 4};
    int *p = arr; // p points to the same array as arr

    // we can access elements in a number of ways
    // **
    // Arrays are not size-aware, 
    // don't access elements that are out of range!!!
    // ** 
    cout << "{" << arr[0] << ", " << p[1] << ", " << *(arr+2) << ", " << *(&p[0]+3) 
        << ", " << p[4] << "}" << endl;

    // pointer dereferencing also works for assignments, e.g.
    *(&arr[0]+3) = -1;
    cout << "{" << arr[0] << ", " << p[1] << ", " << *(arr+2) << ", " << *(&p[0]+3) 
        << ", " << p[4] << "}" << endl << endl;

    // -------------------

    // 2D static arrays are stored in row-major order
    // Example: 3 rows x 4 columns
    int mat[3][4] {{0, 1, 2, 3},{4, 5, 6, 7},{8, 9, 10, 11}};

    for(size_t r = 0; r < 3; r++) {
        cout << "{";
        for(size_t c = 0; c < 4; c++ ) {
            // familiar row, column indexing
            cout << mat[r][c] << ", ";
        }
        cout << "}" << endl;
    }
    cout << endl;

    // The 2D array is contiguous in memory
    cout << "{";
    for(size_t i = 0; i < 12; i++) {
        // mat[0] points to the first element
        cout << *(mat[0]+i) << ", ";
        // equivalently
        // cout << *(&mat[0][0]+i) << ", ";  
    }
    cout << "}" << endl;

    // Mixing prefix '*' and postfix '[]' can be confusing 
    
    int (*q)[4] = mat; // What is this? Why are parentheses necessary?
    
    //q[i] is an array of 4 elements
    //so double indexing q should work as expected
    for(size_t r = 0; r < 3; r++) {
        cout << "{";
        for(size_t c = 0; c < 4; c++ ) {
            cout << q[r][c] << ", ";
        }
        cout << "}" << endl;
    }
    cout << endl;

    // -----------------------------

    // Dynamically allocated 1D and 2D arrays

    // 1D array
    int *darr = nullptr;
    darr = new int[10] {0, 1, 2, 3, 4}; // rest default initialized
    for(size_t i = 0; i < 10; i++) {
        cout << darr[i] << ", ";
    }
    cout << endl << endl;

    // 2D array that uses familiar double index
    int **darr2 = new int*[3]; // for 3 rows
    for(size_t i = 0; i < 3; i++) {
        darr2[i] = new int[4]; // 4 columns
    }

    // This array has familiar row-major ordering but must be double indexed.
    size_t cnt = 0;
    cout << "{";
    for(size_t r = 0; r < 3; r++) {
        cout << "{";
        for(size_t c = 0; c < 4; c++) {
            darr2[r][c] = cnt++;
            cout << darr2[r][c] << ", ";  
        }
        cout << "}" << endl;
    }
    cout << endl << endl;

    delete[] darr;
    darr = nullptr;

    // For the 2D array, each 1D array dynamically 
    // allocated must be deleted

    for(size_t r = 0; r < 3; r++) {
        delete[] darr2[r];
    }
    darr2 = nullptr;

    return 0;
}

