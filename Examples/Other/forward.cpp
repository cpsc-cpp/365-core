#include <iostream>
#include <utility>
#include <memory>

using namespace std;

class A {
    int _i;
    
public:
    A( int& x ) : _i{x} {cout << "lvalue constructor called" << endl;}
    A( int&& x ) : _i{x} {cout << "rvalue constructor called" << endl;}

    // copy and move
    A (const A& a) : _i{a._i} {cout << "copy constructor called" << endl;}
    A (const A&& a) : _i{a._i} {cout << "move constructor called" << endl;}

    // destructor
    ~A() {cout << "destructor called" << endl;}

    friend A operator+(const A&, const A&);
};

A operator+(const A& a1, const A& a2 ) {
    A result {a1};
    result._i += a2._i;
    return result;
}


template<class T, class U>
std::unique_ptr<T> make_unique(U&& u)
{
    return std::unique_ptr<T>(new T(std::forward<U>(u)));
}



int main() {
    int i = 3;
    auto a1 = make_unique<A>( 5 );
    A a2 { 4 };

    A a3 { *a1 + a2 }; 
    return 0;
}