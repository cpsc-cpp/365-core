#include <iostream>

using namespace std;

void print( int a ) {
    std::cout << "int: " << a << "\n";
}

void print( double a ) {
    std::cout << "double: " << a << "\n";
}

int main() {
    print(5); // exact match
    print(5.1); // exact match
    //print(5L); // ambiguous
    print(static_cast<double>(5L)); // resolve ambiguity
}