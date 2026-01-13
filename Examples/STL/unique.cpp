#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {

  auto print = [](const string &s) { cout << s << " "; };

  vector<string> words = {"the",  "quick", "brown", "fox",  "jumps",
                          "over", "the",   "brown", "lazy", "dog"};
  for_each(words.cbegin(), words.cend(), print);
  cout << endl;

  //sort(words.begin(), words.end());
  for_each(words.cbegin(), words.cend(), print);
  cout << endl;

  auto itr = unique(words.begin(), words.end());
  for_each(words.cbegin(), words.cend(), print);
  cout << endl;
  
  words.erase(itr, words.end());
  for_each(words.cbegin(), words.cend(), print);
  cout << endl;
}