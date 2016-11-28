#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  string temp;
  int weigh[] = {10,9,8,7,6,5,4,3,2};
  while (cin >> temp) {
    int ans = 0;
    int dig = 0;
    for (size_t i = 0; i < temp.length(); i++) {
      if (temp[i] >= '0' && temp[i] <= '9') {
        ans += (temp[i] - '0')*(weigh[dig++]);
      }
    }
    // cout << ans % 11;
    if (ans % 11 == 0) {
      cout << temp << "-" << "0" << endl;
    } else if (ans % 11 == 1){
      cout << temp << "-" << "X" << endl;
    } else {
      cout << temp << "-" << (11 - (ans % 11)) << endl;
    }
  }
  return 0;
}
