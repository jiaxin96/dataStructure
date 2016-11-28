#include <string>
#include <iostream>
#include <set>
#include <map>
using namespace std;
bool match(string  a, string  b) {
  for (size_t i = 0; i < a.length(); i++) {
    if (a[i] == 'A' && b[i] != 'T') return false;
    if (a[i] == 'T' && b[i] != 'A') return false;
    if (a[i] == 'G' && b[i] != 'C') return false;
    if (a[i] == 'C' && b[i] != 'G') return false;
  }
  return true;
}
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::map<int, std::multiset<string> > ans;
    int n;
    std::cin >> n;
    while (n--) {
      string temp;
      cin >> temp;
      ans[temp.length()].insert(temp);
    }
    int matchCount = 0;
    for (std::map<int, multiset<string> >::iterator it = ans.begin();
    it != ans.end(); it++) {
      multiset<string>::iterator tit = it->second.end();
      tit--;
      for (multiset<string>::iterator it2 = it->second.begin();
      it2 != tit; it2++) {
        for (multiset<string>::iterator it3 = it2;
        it2 != it->second.end(); it2++) {
          if (match((*it2), (*it3))) {
            it->second.erase(it3);
            matchCount++;
          }
        }
      }
      cout << matchCount << endl;
    }
  }
  return 0;
}
