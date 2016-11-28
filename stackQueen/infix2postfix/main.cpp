#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool big(char c1, char top) {
  int b1 = 1, b2 = 1;
  if (c1 == '%' || c1 == '/' || c1 == '*') {
    b1 = 2;
  }
  if (top == '%' || top == '/' || top == '*') {
    b2 = 2;
  }
  return (b1 > b2);
}

int main(int argc, char const *argv[]) {
  string str;
  cin >> str;
  stack<char> sta;
  // cout << str << "###";
  for (size_t i = 0; i < str.size(); i++) {
    if (isalpha(str[i])) {
      cout << str[i];
    } else {
      if (sta.empty()) {
        sta.push(str[i]);
      } else {
        while(!sta.empty() && !big(str[i], sta.top())) {
          cout << sta.top();
          sta.pop();
        }
        sta.push(str[i]);
      }
    }
  }
  while (!sta.empty()) {
    cout << sta.top();
    sta.pop();
  }
  return 0;
}
