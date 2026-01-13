#include <memory>
#include <iostream>
#include <vector>
#include "../Classes/virtual.h"

using namespace std;

// use int[] rather than int for array types
unique_ptr<int[]> makeArray(size_t n) {
    unique_ptr<int[]> result {new int[n] {}};
    return result; // will invoke move which transfers ownership
}

int main() {

    // Basic usage:
    // allocate object on heap, don't need to worry about deletion    
    unique_ptr<Employee> emp {new Employee{ "Alpha", 365}};
    emp->print();
    cout << endl;
    
    // derived to base conversion and polymorphism
    emp.reset( new Manager { "Bravo", 365, 2 } );
    emp->print(); 
    cout << endl;

    // Use inside container
    cout << endl;
    vector< unique_ptr<Employee> > emps;
    emps.push_back( unique_ptr<Employee> {emp.release()}); // transfer ownership
    emps.push_back( unique_ptr<Employee> {new Employee {"Charlie", 399} });
    emps.push_back( unique_ptr<Employee> {new Manager {"Delta", 399, 3} });
    emps.push_back( unique_ptr<Employee> {new Employee {*emps.back()}}); // copy with slicing

    for( const auto &emp : emps) {
        emp->print();
        cout << endl;
    }

    cout << endl;

    // indexing an array
    unique_ptr<int[]> arr = makeArray(10);
    for(size_t i=0; i < 10; i++) cout << arr[i] << " ";

    cout << endl;

    return 0;
}  