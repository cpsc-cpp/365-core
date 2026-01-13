#include <cstring>
#include <iostream>
#include <vector>

template <typename Itr> 
auto mean( Itr begin, Itr end ) 
    -> typename Itr::value_type 
{
    using T = typename Itr::value_type;
    T result{};
    size_t count = 0; 
    for( Itr itr = begin; itr != end; itr++) {
        result += *itr;
        count++;
    }
    return result / count;
}

template <typename T> T mean(T* begin, T* end) {
    T result{};
    size_t count = 0; 
    for( T* itr = begin; itr != end; itr++) {
        result += *itr;
        count++;
    }
    return result / count; 
    
}

using namespace std;

int main() {
    vector<double> d {0.0, 1.0, 2.0, 3.0, 4.0};
    double arr[5] {0.0, 1.0, 2.0, 3.0, 4.0};

    cout << mean(d.begin(), d.end()) << endl;
    cout << mean(arr, arr+5) << endl;
    return 0;
}
