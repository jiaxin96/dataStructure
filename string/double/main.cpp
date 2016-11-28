#include <iostream>
#include <set>
// #include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    set<int> s;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int temp;
      cin >> temp;
      // for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
      //
      // }
      s.insert(temp);
      if (temp % 2 == 0 && (s.find(temp / 2) != s.end())) {
        // cout << "f" << endl;
        ans++;
      }
      if (s.find(2*temp) != s.end())
      {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
