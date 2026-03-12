/**
 * @file poly.h
 * @brief A class to represent univariate polynomials.
 *  
 * Class and function declarations for a univariate polynomial.  
 */

#ifndef POLY_H
#define POLY_H

#include <cstdint>
#include <cstdlib>
#include <initializer_list>
#include <list>
#include <utility>


class Poly{
    //privates

    // Represent a polynomial as a list of (coeff, exp) pairs
    // that is maintained in sorted order
    std::list<std::pair<int32_t, uint32_t>> poly;

    //helper method to combine duplicate terms in poly list
    void my_combine();

    // comparator function used for sorting, compares
    // exponents
    static bool comp( const std::pair<int32_t, uint32_t> &a, 
                      const std::pair<int32_t, uint32_t> & b) {
        return a.second < b.second;
    }


public: 

    // Default constructs the zero polynomial.
    Poly() : Poly(0) {}

    //Construct a monomial from provided coefficient and exponent
    Poly(int32_t coeff, uint32_t exponent = 0);

    // Construct a polynomial from an initializer_list of 
    // {coefficient, exponent} pairs.
    // The pairs may be in any order.
    // If there are repeated exponents, their coefficients are simply
    // added together to construct a polynomial with unique exponents. 
    Poly(std::initializer_list<std::pair<int32_t,uint32_t>> lst);

    // Copy and move operations are defaulted.
    // Please change if your class needs non-defaults.
    Poly(const Poly&) = default;
    Poly& operator=(const Poly&) = default;
    Poly(Poly&&) = default;
    Poly& operator=(Poly&&) = default;

    // Destructor is also defaulted.
    // Please change if your class needs a non-default destructor
    ~Poly() = default;

    // Returns polynomial in list form in descending order by exponent
    // Terms with zero coefficients are not included in the list. 
    std::list<std::pair<int32_t, uint32_t>> to_list() const;

    // Evaluates the polynomial at the integer x
    int32_t operator()(int32_t x) const;

    // non-member binary operators declared as friends

    // Performs the operation a+b where a and b are polynomials.
    // Here, '+' refers to polynomial addition 
    // Returns the resulting polynomial.
    friend Poly operator+(const Poly& a, const Poly& b);
    
    // Performs the operation a-b where a and b are polynomials.
    // Here, '-' refers to polynomial subtraction.
    // Returns the resulting polynomial.
    friend Poly operator-(const Poly& a, const Poly& b);

    // Performs the operation a*b where and b are polynomials.
    // Here, '*' represents polynomial multiplication.
    // Returns the resulting polynomial.
    friend Poly operator*(const Poly& a, const Poly& b);
};

// Fun with polynomials

// The following functions can be used to ensure that your polynomials 
// are working as expected

// Returns entries of Pascal's triange upto and including row n.
// The entries in row n (n >= 0) are the coefficients 
// of the expansion: (1+x)^n. 
std::list<std::list<int32_t>> pascal_triangle(size_t n=1);

// Returns the n-th (n>=0) Fibonacci polynomial.
// Fibonacci polynomials F_n are defined by the recurrence:
// F_n = 0, if n = 0
// F_n = 1; if n = 1
// F_n(x) = x * F_{n-1}(x) + F_{n-2}(x)
//
// F_n(1) should return the n-th Fibonacci number, i.e.
// the returned polynomial when evaluated at 1 should yield 
// the n-th Fibonacci number.
Poly fib_poly(size_t n=2);

#endif