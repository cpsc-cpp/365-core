/**
 * @file structs.cpp
 * @brief Basic encapsulation via structures 
 *  
 * Structures offer a basic encapsulation menchanism.
 * They are contiguous in memory and can also be used to 
 * encapsulate arrays and bit fields
 * 
 */

#include <iostream>
#include "common.h"

using namespace std;

int main() {
    TupleA ta {'a', 0, 'b'};
    TupleB tb {0, 'a', 'b'};
    Record rd {"Jon Doe", 2025, {'A', 'B'}};
    
    cout << "Size of TupleA (in bytes): " << sizeof(ta) << endl;
    cout << "Size of TupleB (in bytes): " << sizeof(tb) << endl;
    cout << "Size of Record (in bytes): " << sizeof(rd) << endl;

    // members can be access via the familiar '.' syntax
    rd.name = "Jane Doe";
    cout << "{" << rd.name << ", " << rd.id << ", " 
        << rd.province[0] << rd.province[1] << "}" << endl;
    print_record( &rd );

    // Can also pass by value, structs behave like public classes.
    // More on this later
    print_record_value( rd );

    // print original record
    print_record( &rd );

    cout << endl;

    // We can have an array of structs,
    // let's allocate on free store with initialization 
    Record* data = new Record[3] {
        {"Alpha", 0, {'A','B'}},
        {"Bravo", 1, {'B','C'}},
        {"Charlie", 2, {'M','B'}}
    };
    
    for(size_t i = 0; i < 3; i++) {
        print_record(&data[i]);
    }    
    
    delete[] data;

    // Let's work with fields

    MyInt i {127, 1};
    cout << "Size of MyInt (in bytes): " << sizeof(i) << endl;
    cout << convert_my_int(&i) << endl;

    return 0;
}


