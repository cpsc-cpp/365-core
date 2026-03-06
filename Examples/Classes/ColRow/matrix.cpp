#include "matrix.h"
#include <iostream>

using namespace std;

const size_t N = 4096;

int main() {
    SquareMatrix* M1 = new ColMajor{N};
    // lower triangular matrix of ones
    for(size_t r = 0; r < N; r++) {
        for(size_t c = 0; c < r; c++) { 
            M1->at(r,c) = r*1.0;
        }
    }

    vector<double> vec(N,1.0);
    vector<double> v1 = *M1 * vec;

    delete M1;
    return 0;
}
