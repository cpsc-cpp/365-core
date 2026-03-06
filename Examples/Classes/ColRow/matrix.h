/**
 * A simple class hierarchy for representing square
 * matrices via row-major or column-major ordering.
 * 
 */

#include <cstdlib>
#include <vector>
#include <ostream>

// abstract base class for a square matrix
class SquareMatrix {
protected:
    size_t n;
    SquareMatrix( size_t N ) : n{N} {}

public:
    virtual double& at(size_t row, size_t col) = 0;
    virtual std::vector<double> operator*(const std::vector<double>& vec) = 0;

    virtual ~SquareMatrix() {};

    friend std::ostream& operator<<(std::ostream& out, SquareMatrix& mat) {
        for(size_t r = 0; r < mat.n; r++) {
            for(size_t c = 0; c < mat.n; c++) {
                out << mat.at(r,c) << " ";
            }
            out << std::endl;
        }
        return out;
    }


};


// Row major ordering
class RowMajor : public SquareMatrix {
protected:
    
    // matrix represented as a vector of rows
    std::vector<std::vector<double>> mat;
    
public:
    RowMajor(size_t N) : SquareMatrix{N} , mat{n, std::vector<double>(n) } {}
    
    double& at(size_t row, size_t col) override {
        return mat[row][col];
    }
    
    std::vector<double> operator*(const std::vector<double>& vec) override {
        std::vector<double> result(n, 0.0);
        for(size_t r = 0; r < n; r++) {
            for( size_t c = 0; c < n; c++ ) {
                result[r] += this->at(r,c)*vec[r];
            }
        }
        return result;
    }
};

// Column major ordering
class ColMajor : public RowMajor {
        
public:
    ColMajor(size_t N) : RowMajor{N} {}

    // Don't need a separate vector.
    // Can simply transpose the row-major version
        
    double& at(size_t row, size_t col) override {
        return mat[col][row];
    }     
};

