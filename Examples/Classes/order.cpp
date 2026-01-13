#include <iostream>

using namespace std;

struct A {
    // prevent default construction
    A(int i) { cout << "Constructing A" << endl;}

    // Virtual base class destructor will make 
    // all destructors in hierarchy virtual. 
    virtual ~A() {cout << "Cleaning up A" << endl;}
};
struct B : A {
    B() : A{0} { cout << "Constructing B" << endl;}
    ~B() {cout << "Cleaning up B" << endl;}
};
struct C : B {
    C() { cout << "Constructing C" << endl;}
    ~C() {cout << "Cleaning up C" << endl;}
};

int main() {
    cout << "Construction..." << endl;
    C* obj = new C {};
    cout << endl;
    cout << "Clean up..." << endl;
    delete obj;
    cout << endl;    
}