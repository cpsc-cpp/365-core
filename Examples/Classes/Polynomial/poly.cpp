/**
 * @file poly.cpp
 * @brief Univariate polynomial
 *  
 * Implementation of Poly class and associated functions.
 * Please use this file to provide all definitions that are declared
 * in class Poly.
 */

#include "poly.h"
#include <algorithm>
#include <iterator>

using namespace std;

// helper method to remove zeros and combine adjacent duplicate terms
void Poly::my_combine() {
    uint32_t exp = poly.begin()->second;
    for( auto itr=poly.begin(); itr != prev(poly.end()); ) {
        if ( next(itr,1)->second == exp ) {
            next(itr,1)->first += itr->first;
            itr = poly.erase(itr);
        } else {
            exp = (++itr)->second;
        }
    }
    poly.remove_if([](const pair<int32_t, uint32_t> &term){ return term.first == 0; });
}

//Construct a monomial from provided coefficient and exponent
Poly::Poly(int32_t coeff, uint32_t exponent) {
    // store it only if coefficient is non-zero
    if(coeff != 0) {
        poly.push_back( {coeff, exponent} );
    }
}

// initializer list constructor 
Poly::Poly(initializer_list<pair<int32_t,uint32_t>> lst) {
    for(auto pair : lst) {
        poly.push_back(pair);
    }
    // sort list
    poly.sort(comp);
    // combine duplicates if any
    my_combine();
}

// Returns polynomial in list form in descending order by exponent
list<pair<int32_t, uint32_t>> Poly::to_list() const {
    auto result = poly;
    result.reverse();
    return result;
}

// Evaluates the polynomial at the integer x
// using Horner's method. Accounts for  
int32_t Poly::operator()(int32_t x) const {
    if(poly.empty())
        return 0;

    uint32_t degree = poly.back().second;
    int32_t result = poly.back().first;
    auto itr = poly.rbegin();
    while( degree ) {
        degree--;
        int32_t coeff = 0;
        if( next(itr,1) != poly.rend() && next(itr,1)->second == degree ) {
            coeff = next(itr,1)->first;
            itr++;
        }
        result = x * result + coeff;
    }
    return result;      
}

// Binary addition operator for two polynomials
Poly operator+(const Poly& a, const Poly& b) {
    // a and b are already sorted,
    // so we can simply merge the lists 

    Poly result;
    //result.poly.clear();
    result.poly.resize( a.poly.size() + b.poly.size() );
    merge(a.poly.begin(), a.poly.end(), 
          b.poly.begin(), b.poly.end(), 
          result.poly.begin(), Poly::comp);
    result.my_combine();
    return result;
}

// Binary subtraction operator for two polynomials
Poly operator-(const Poly& a, const Poly& b) {
    // negate b and delegate to operator+
    Poly _b {b};
    for(auto &term : _b.poly)
        term.first *= -1;
    return a+_b;
}

// Binary multiplication operator for two polynomials
Poly operator*(const Poly &a, const Poly &b) {
  Poly result;
  // result.poly.clear();

  if (a.poly.size() > 0 && b.poly.size() > 0) {
    for (auto const &p : a.poly) {
      for (auto const &q : b.poly) {
        result.poly.push_back({p.first * q.first, p.second + q.second});
      }
    }
    result.poly.sort(Poly::comp);
    result.my_combine();
  }
  return result;
}

// Fun with polynomials

// Returns entries of Pascal's triange upto and including row n.
// The entries in row n (n >= 0) are the coefficients 
// of the expansion: (1+x)^n. 
list<list<int32_t>> pascal_triangle(size_t n) {
    list<list<int32_t>> result;
    result.push_back( {1} ); // entry for row 0
    if( n > 0 ) {
        Poly base {{1,0},{1,1}}; // 1 + x
        Poly b {{1,0},{1,1}}; // 1 + x
        result.push_back( {1,1} ); // entry for row 1
        if( n > 1 ) {
            for(size_t i = 2; i <= n; i++ ) {
                result.push_back( {} );
                b = b*base;
                for(const auto& el : b.to_list()) {
                    result.back().push_back(el.first);
                }
            }
        }
    }
    return result;
}

// Returns the n-th (n>=0) Fibonacci polynomial.
// Fibonacci polynomials F_n are defined by the recurrence:
// F_n = 0, if n = 0
// F_n = 1; if n = 1
// F_n(x) = x * F_{n-1}(x) + F_{n-2}(x)
//
// F_n(1) should return the n-th Fibonacci number, i.e.
// the returned polynomial when evaluated at 1 should yield 
// the n-th Fibonacci number.
Poly fib_poly(size_t n) {
    if( n == 0 || n == 1 ) {
        return Poly{n};
    } else {
        return Poly{{1,1}} * fib_poly(n-1) + fib_poly(n-2);
    }
}

