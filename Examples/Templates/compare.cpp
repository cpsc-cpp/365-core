#include <cstring>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
int compare( const T& e1, const T& e2 ) {
    cout << "Main version called..." << endl;
    if (e1 < e2) return -1;
    if (e2 < e1) return 1;
    return 0;
}

// specialization for char pointers
template <> int compare ( const char* const &p1, const char* const & p2) {
    cout << "Specialized version called..." << endl;
    return strcmp(p1, p2);
}

// overload for string literals and strings
template <size_t N, size_t M>
int compare( const char (&e1)[N], const char (&e2)[M] ) {
    cout << "Overloaded version called..." << endl;
    if ( string{e1} < string{e2} ) return -1;
    if ( string{e1} > string{e2} ) return 1;
    return 0;
}

int main() {
    cout << compare(1,2) << endl;
    
    // Need to disambiguate
    cout << compare<3,3>("aa", "bb") << endl;

    // pointer to char
    const char *p1 = "hello";
    const char *p2 = "world";

    cout << compare(p1, p2) << endl;
    cout << compare(string{p1}, string{p2}) << endl;
}
