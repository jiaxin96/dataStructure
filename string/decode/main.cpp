#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  string str;
  while (cin >> str && str != "XXX") {
    for (int i = 0; i < str.length(); ++i) {
      int num = 0;
      if (str[i] >= 'a' && str[i] <= 'z') {
        cout << str[i];
      } else {
        num += (str[i] - '0');
        int lette = i - 1, j;
        for (j = i + 1; j < str.length(); ++j) {
          if (str[j] >= 'a' && str[j] <= 'z') {
            break;
          }
          num *= 10;
          num += (str[j] - '0');
        }
        i = j - 1;
        for (int k = 1; k < num; ++k) {
          std::cout << str[lette];
        }
      }
    }
    std::cout << std::endl;
    str = "";
  }
  return 0;
}
