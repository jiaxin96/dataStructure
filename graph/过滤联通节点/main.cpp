#include <hash_set>
#include <vector>
#include <cstdio>
using namespace std;
using namespace __gnu_cxx;
int main(int argc, char const *argv[])
{
    std::vector<hash_set<int>> v;
    int a,b;
    while (scanf("%d%d", &a, &b) != EOF) {
        int va = -1;
        int vb = -1;
        bool finda;
        bool findb;
        hash_set<int>::iterator it;
        for (int i = 0; i < v.size(); ++i)
        {
            finda = findb = false;
            it = v[i].end();
            if (va == -1) finda = (v[i].find(a) != it);
            if (vb == -1) findb = (v[i].find(b) != it);
            if (finda && findb) {
                va = vb = i;
                break;
            } else if (findb) {
                v[i].insert(a);
                vb = i;
                if (va != -1) break;
            } else if (finda) {
                v[i].insert(b);
                va = i;
                if (vb != -1) break;
            }
        }
        if (va != vb) {
            if (va != -1 && vb != -1) {
                v[va].insert(v[vb].begin(), v[vb].end());
                v[vb].clear();
            }
            printf("%d %d\n", a, b);
        } else if (va == -1 && vb == -1) {
            hash_set<int> temp;
            temp.insert(a);
            temp.insert(b);
            v.push_back(temp);
            printf("%d %d\n", a, b);
        }
    }
    return 0;
}