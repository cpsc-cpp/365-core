#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

  vector<string> vec = {"5", "5", "6", "0", "1", "2", "0", "2", "3", "4"};
  map<string, size_t> wc;
  for (auto &s : vec) {
    ++wc[s]; // automatically inserts keys if not already in map.
  }
  // adding via insert
  wc.insert({"10", 3}); // inserts an element of type pair<string, size_t>
  // iterate over map value_type using range-for
  // can also use an iterator
  for (const auto &w : wc) { // w is of type pair<string, size_t>
    cout << w.first << " --> " << w.second << endl;
  }
  // find something in the map, find returns an iterator
  cout << wc.find("10")->second << endl;
}