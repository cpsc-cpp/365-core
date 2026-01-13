#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// A custom hash function
size_t my_hash(const int i) {
    return (i / 10) % 10;
}

// A custom equality function
bool my_eq(const int &i, const int &j) {
    return (i / 10) % 10 == (j / 10) % 10;
}

int main() {
    using umap = unordered_map<int, size_t, decltype(my_hash)*, decltype(my_eq)*>;
    umap hist(10, my_hash, my_eq);
    
    for(int i = 0; i < 100; i++) {
        ++hist[i];
    }
    
    // tmraverse using an iterator
    auto it = hist.cbegin();
    while(it != hist.cend()) {
        cout << it->first << " --> " << it->second << endl;
        it++;
    }
}