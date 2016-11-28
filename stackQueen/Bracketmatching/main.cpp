/*
Time Limit: 1sec    Memory Limit:256MB
Description
检查输入字符串中的括号是否匹配。括号包括：{, }, (, ), [, ].
Input
第一行是一整数，即测试样例个数n.
以下n行，每一行是一个长度不超过100个字符的字符串。
Output
第一行是一整数，即测试样例个数n.
以下n行，每一行是一个长度不超过100的字符串。
Sample Input
 Copy sample input to clipboard
3
a
2-[(1+2)*2]
(a+b])
Sample Output
Yes
Yes
No
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isOk(string s) {
  stack<char> ans;
  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
      ans.push(s[i]);
    } else if (s[i] == ')') {
      if (!ans.empty() && ans.top() == '(') {
        ans.pop();
      } else {
        ans.push(s[i]);
      }
    } else if (s[i] == ']') {
      if (!ans.empty() && ans.top() == '[') {
        ans.pop();
      } else {
        ans.push(s[i]);
      }
    } else if (s[i] == '}') {
      if (!ans.empty() && ans.top() == '{') {
        ans.pop();

      } else {
        ans.push(s[i]);
      }
    }
  }
  return ans.empty();
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (isOk(s)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
