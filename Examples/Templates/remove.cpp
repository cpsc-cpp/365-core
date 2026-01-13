#include <iostream>

template <typename T> struct remove_ref {
    typedef T type;
};
// specialization for lvalue refs
//

template <typename T> struct remove_ref<T&> {
typedef T type;
};
//  specialization for rvalue refs
template <typename T> struct remove_ref<T&&> {
    typedef T type;
};

using namespace std;

int main() {
    int a {365};
    remove_ref<int&&>::type b {a};
    b++;
    cout << "a: " << a << " b: " << b << endl;  
}
