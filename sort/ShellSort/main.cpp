// Problem#: 19189
// Submission#: 4988736
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <map>
using namespace std;

void Rsort(vector<string> & li, std::vector< list<string> > & v, int pos, int n) {
    for (int i = 0; i < 10; ++i)
    {
        v[i].clear();
    }
    for (int i = 0; i < n; ++i)
    {
        v[li[i][pos] - '0'].push_back(li[i]);
    }
    li.clear();

    for (int i = 0; i < 10; ++i)
    {
        for (list<string>::iterator it = v[i].begin(); it != v[i].end(); ++it) {
            li.push_back(*it);
        }
    }
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> li;
        for (int i = 0; i < n; ++i)
        {
            string temp = "";
            for (int i = 0; i < m; ++i)
            {
                string tt;
                cin >> tt;
                temp += tt;
            }
            li.push_back(temp);
        }
        std::multimap<int, int, greater<int> > pri;
        int q;
        cin >> q;
        for (int i = 0; i < q; ++i)
        {
            pri.clear();
            vector<string> tli = li;
            std::vector< list<string> > v(10);
            for (int j = 0; j < m; ++j)
            {
                int tp;
                cin >> tp;
                pri.insert(pair<int,int>(tp, j));
            }
            for (std::multimap<int, int, greater<int> >::iterator it = pri.begin(); it != pri.end(); it++) {
                Rsort(tli, v, it->second, n);
            }
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (tli[i] == li[j]) {
                        if (i != n - 1) cout << j << " ";
                        else cout << j << endl;
                        break;
                    }
                }
            }
        }

    }
    return 0;
}                                 