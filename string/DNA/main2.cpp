#include <string>
#include <iostream>
#include <set>
  using namespace std;
  bool match(string a, string b) {
    if (a.length() != b.length()) return false;
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
    int n;
    std::multiset<string> ans;
    std::cin >> n;
    int matchCount = 0;
    while (n--) {
      string temp;
      cin >> temp;
      bool flag = false;
      for (multiset<string>::iterator it = ans.begin(); it != ans.end(); ++it) {
        if (match(temp, *it)) {
          matchCount++;
          ans.erase(it);
          flag = true;
          break;
        }
      }
      if (!flag) {
        ans.insert(temp);
      }
    }
    std::cout << matchCount << std::endl;
  }
  return 0;
}
