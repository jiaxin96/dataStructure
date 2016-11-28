#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isBlank(string temp) {
  if (temp == "") return true;
  int l = temp.length();
  for (size_t i = 0; i < l; i++) {
    if (temp[i] != ' ') return false;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  string temp = "";
  std::vector<string> ans;
  int strCount = 0;
  while (getline(cin, temp)) {
    strCount++;
    if (isBlank(temp)) {
      ans.push_back("");
      continue;
    }
    string temp2 = "";
    int len = temp.length();
    int mid = 0;
    if (len % 2 == 0) {
      mid = len / 2 - 1;
    } else {
      mid = len / 2;
    }
    for (int i = mid; i >= 0; --i) {
      temp2 += temp[i];
    }
    mid++;
    for (int i = len - 1; i >= mid; --i) {
      temp2 += temp[i];
    }
    ans.push_back(temp2);
    temp = "";
  }
  if (strCount % 2 == 1) {
    ans.push_back("");
  }
  for (size_t i = 0; i < ans.size() / 2; i++) {
    if (ans[2*i+1] != "") cout << ans[2*i+1] << endl;
    if (ans[2*i] != "") std::cout << ans[2*i] << std::endl;
  }
  return 0;
}
