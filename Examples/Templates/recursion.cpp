#include <cstdlib>
#include <iostream>

// Evaluate polynomial (1+x)^n.

template<size_t N, typename T> T poly(T x) {
    return (1+x) * poly<N-1,T>(x);
}

template<> double poly<0,double>(double x ) {
    return 1.0;
}

template<> int poly<0,int>(int x ) {
    return 1;
}

using namespace std;

int main() {
    cout << poly<5,double>(1.1) << endl;
}
