#include <cstdio>
#include <cstring>
using namespace std;
#include <iostream>
bool match(int pos, int fix[], int aim[], int lfix, int laim) {
  int matchCount = 0;
  for (int i = pos + 1; i < lfix; ++i) {
    if (i - pos < laim && aim[i - pos] == fix[i]) {
      matchCount++;
    } else {
      break;
    }
  }
  if (matchCount + 1 == laim) return true;
  return false;
}

int main(int argc, char const *argv[]) {
  int n;
  int m;
  int aim[60005];
  int fix[60005];
  int ans;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; ++i) {
      scanf("%d ", &aim[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
      scanf("%d", &fix[i]);
    }
    bool flag = false;
    for (int i = m - 1; i >= 0; --i) {
      if (fix[i] == aim[0]) {
        if (match(i, fix, aim, m, n)) {
          flag = true;
          cout << i << endl;
          break;
        }
      }
    }
    if (!flag) {
      printf("no solution\n");
    }
  }
  return 0;
}
