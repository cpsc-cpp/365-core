/**
 * @file references.cpp
 * @brief Introduction to references 
 *  
 *  Basic lvalue references in C++.
 */

#include <iostream>
#include "common.h"

using namespace std;

int main() {

    Record r {"Chris", 5, {'A','B'}};
    Record& r_alias {r}; // rd_alias is an lvalue reference

    // cannot do the follwing, need an rvalue reference (more on that later).
    //Record& rd1 {"Bob", 365, {'A', 'B'}};

    print_record(&r); // pass a pointer
    print_record(r); // pass by reference
    
    // instead of using object directly, we can use a reference to it.
    // rd_alias behaves just like rd
    print_record(&r_alias); // takes the address of the original object
    print_record(r_alias);  // passing a reference by reference
    
    // what if object is in the free store?

    Record* f = new Record {"Bob", 365, {'A', 'B'}};
    Record& fr {*f}; // reference to f

    print_record(f); // This will do the trick
    print_record(*f); // Can also pass by reference
    print_record(fr); // This is also pass by reference

    delete f;
    return 0;
}