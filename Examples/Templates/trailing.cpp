#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <type_traits>


template <typename Itr> 
auto process1( Itr begin, Itr end ) -> decltype(*begin) {
    for(Itr itr = next(begin,1); itr != end; itr++)
        *begin += *itr;
    return *begin;
}

template <typename Itr> 
auto process2( Itr begin, Itr end ) -> 
    typename std::remove_reference<decltype(*begin)>::type 
{
    using T = typename std::remove_reference<decltype(*begin)>::type;
    return std::accumulate(begin, end, T{});
}

using namespace std;

int main() {
    vector<int> v {0,1,2,3,4};
    vector<string> s {"It", "is", "warm", "today"};

    // Return is a reference type
    // what if we change the iterators to const, cbegin, cend?

    cout << process1(v.begin(), v.end()) << endl;
    cout << process1(s.begin(), s.end()) << endl;
    //cout << accumulate(s.cbegin(), s.cend(), string{}) << endl;

    // The following return by value
    cout << process2(v.begin(), v.end()) << endl;
    cout << process2(s.begin(), s.end()) << endl;
}
