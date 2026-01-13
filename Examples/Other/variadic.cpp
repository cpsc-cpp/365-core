#include <iostream>

template <typename T> double sum( T x ) {
    return static_cast<double>(x); 
}

template <typename T, typename... Tail>
double sum( T head, Tail... tail ) {
    return static_cast<double>(head) + sum(tail...);
}

template <typename... Args>
double mean( Args... args ) {
    return 1.0/sizeof...(args) * sum(args...);
}

using namespace std;

int main() {
    cout << mean(1, 2, 3.0, 4.0f, 5.5) << endl;
}