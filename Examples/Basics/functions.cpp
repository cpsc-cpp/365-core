/**
 * @file functions.cpp
 * @brief Function Pointers and Lambdas
 * 
 * Working with function pointers and lambda expressions.
 */

#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>


using namespace std;

const double PI = std::acos(-1); 

// A point in 3D
struct Point {
    double x; 
    double y; 
    double z;
};

// in-place application of a function to 
// points in an array
void apply( Point points[], size_t N, void (*func)(Point&) ) {
    for(size_t i=0; i < N; i++) {
        func(points[i]);
    }
}

// A quadratic function
void quad( Point& p ) {
    p.z = p.x*p.x + p.y*p.y; 
}

// A trig function
void trig( Point& p ) {
    p.z = sin(2.0 * PI * p.x) * cos(2.0 * PI * p.y);
}

int main() {
    void (*print)(Point&) = [](Point& p){ cout << "(" << p.x << ", " << p.y << ", " << p.z << ") "; };

    constexpr int N = 3;
    Point points[N] {{0.0, 0.0, 0.0}, {0.5, 0.5, 0.0}, {1.0, 1.0, 0.0}};
    
    apply(points, N, print);
    cout << endl;

    apply(points, N, quad);
    apply(points, N, print);
    cout << endl;

    apply(points, N, trig);
    apply(points, N, print);
    cout << endl;

    // One-liners can be passed directly.
    // apply a linear function
    apply(points, N, [](Point& p){ p.z = p.x + p.y; } );
    apply(points, N, print);
    cout << endl;

    // The standard library also provides a for_each function
    for_each(points, points + N, trig );
    for_each(points, points + N, print );
    cout << endl;
}

