#include <iostream>

#include <set>

using namespace std;

int main(int argc, char const *argv[]) {
  set<int> s;
  s.insert(1);
    s.insert(2);
      s.insert(3);
        s.insert(4);
          s.insert(5);
          set<int>::iterator it = s.begin();
          set<int>::iterator it2 = it++;
          it = s.begin();
          s.erase(it);
                    it = s.begin();
          s.erase(it);
          cout << *(s.begin()) << endl;
  return 0;
}
