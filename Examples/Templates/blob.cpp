#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T, size_t N> class Blob;

template <typename T, size_t N> ostream& operator<<(ostream& out, const Blob<T,N>& b);

template <typename T, size_t N> class Blob {
    T arr[N]; // fixed size array
public:
    Blob( T init = T{} ); // default or one-arg constructor
    T& operator[](size_t i) { return arr[i]; } // unchecked access

    Blob( const Blob& b ) = default;
    Blob& operator=( const Blob& b) = default; 
   
    // conversion operator=
    template <typename X> Blob& operator=( const Blob<X,N> &b );

    // all other blobs are friends
    template <typename X, size_t M> friend class Blob;

    friend ostream& operator<< <T>(ostream& out, const Blob<T,N>& b);

};

template<typename T, size_t N>
template<typename X>
Blob<T,N>& Blob<T,N>::operator=( const Blob<X,N> &b ) {
    for(size_t i = 0; i < N; i++ ) {
        arr[i] = static_cast<T>(b.arr[i]);
    }
    return *this;
}

template <typename T, size_t N> 
Blob<T,N>::Blob( T init ) {
    for( size_t i = 0; i < N; i++ ) {
        arr[i] = init;
    }
}

template <typename T, size_t N> ostream& operator<<(ostream& out, const Blob<T,N>& b) {
    out << "[";
    for(size_t i = 0; i < N; i++ ) {
        out << b.arr[i] << ", ";
    }
    out << "]";
    return out;
}

// partial template specialization for 3D blobs
template <typename T> class Blob<T, 3> {
    T _x, _y, _z;

public:
    Blob( T init = T{} ) : _x{init}, _y{init}, _z{init} {}

    // access by name, safer than array indexing
    T& x() {return _x;}
    T& y() {return _y;}
    T& z() {return _z;}
};


int main() {
    Blob<int, 5> i{};
    Blob<double, 5> d {  3.65 }; 
    Blob<string, 5> s { "hello" };
    s[2] += " world";
    cout << s << endl; 
    cout << i << endl;
    
    cout << d << endl;
    i = d;
    cout << i << endl;

    Blob<double,3> point;
    point.x() = point.y() = point.z() = 1.0;
    cout << "(" << point.x() << ", " << point.y() << ", " << point.z() << ")" << endl;
}