#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <functional>
#include <sstream>
#include <map>
#include <stdio.h>
using namespace std;

// github: https://github.com/freedomofme


class Com {
private:
    int k;
public:
    Com(int jj) {
        k = jj;
    }
    bool operator()(vector<int> i, vector<int> j) {
        return i[k] < j[k];
    }
};

int main () {
    freopen("data", "r", stdin);
    int times = 0;
    
    cin >> times;
    
    while (times > 0) {
        times--;

        vector<vector<int> > all;
        
        int row = 0;
        int col = 0;
        
        cin >> row >> col;
        
        for (int i = 0; i < row; i++) {
            vector<int> temp;
            temp.clear();
            for (int j = 0; j < col; j++) {
                int tt = 0;
                cin >> tt;
                temp.push_back(tt);
            }
            temp.push_back(i); //只是为了方便输出结果
            all.push_back(temp);
        }
        
        
        int times2 = 0;
        cin >> times2;
        
        while (times2 > 0) {
            times2--;
            vector<int> v1;
            map<int, int> m;
            for (int i = 0; i < col; i++) {
                int ttt = 0;
                cin >> ttt;
                v1.push_back(ttt);

                m.insert(pair<int, int>(ttt, i));
            }
            
            stable_sort(v1.begin(), v1.end(), greater<int>());
            
            for (int i = 0; i < col; i++) {
                int vt = v1[i];
                map<int, int>::iterator iter = m.find(vt);
                if(iter != m.end()) {
                    stable_sort(all.begin(), all.end(), Com(iter->second));
                }
            }
            
            for (int i = 0; i < all.size() - 1; i++) {
                cout << all[i][col] << " ";
            }
            cout << all[all.size() - 1][col];
            
            cout<<endl;
        }
    }
    
    return 0;
}