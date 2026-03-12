#include "poly.h"
#include <iostream>

using namespace std;

void print( list<pair<int32_t, uint32_t>> lst ) {
    if (lst.empty()) {
        cout << "0";
    } else {
        for(auto itr = lst.begin(); itr != lst.end(); itr++) {
            cout << itr->first << "x^" << itr->second << " + ";
        }
        //cout << lst.back().first;
    }
}

void test_pascal( size_t n ) {
    auto result = pascal_triangle(n);
    for(const auto& lst : result) {
        for(const auto c : lst) {
            cout << c << " ";
        }
        cout << endl;
    }
}

void test_fib( size_t n ) {
    Poly p = fib_poly(n);
    print(p.to_list());
    cout << ":\t" << p(1) << endl;
}

void eval_test() {
    // Evaluate the polynomial (x+1)^n at -1. Should evalute to zero
    Poly base {{1,0},{1,1}};
    Poly p {{1,0},{1,1}};
    for(int i = 0; i < 10; i++) {
        print( p.to_list());
        cout << ":\t" << p(-1) << endl;
        p = p * base;
    }
}



int main() {
    Poly p {{0,0}, {0,1}, {1,0}, {1,1}};
    //Poly p {{1,0},{1,1},{1,1},{1,2},{1,2},{1,2},{1,3},{1,3},{1,4},{1,4}};
    //Poly p {{1,0},{1,1}}; // 1 + x
    //Poly p {1,1};
    print(p.to_list());
    cout << endl;
    print(((p*p*p*p)*(p*p*p*p)).to_list());
    print( (p-p).to_list() );
    cout << endl;

    print((0+Poly{1,1}).to_list());
    cout << endl;
    test_pascal(10);
    
    for(size_t i = 0; i < 10; i++) // don't go too deep as recursion explodes
        test_fib(i);
    cout << endl;
    eval_test();
}