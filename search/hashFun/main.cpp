#include <cstdio>

#include <vector>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
    
    int n;
    bool ff = true;
    while (scanf("%d", &n) && n) {
    std::vector<list<int>> my_hash_map(13);
        for (int i = 0; i < n; ++i)
        {
            int temp;
            scanf("%d", &temp);
            my_hash_map[temp%13].push_back(temp);
        }
        for (int i = 0; i < 13; i++) {
            printf("%d#",i);
            if (my_hash_map[i].size() == 0) {
                printf("NULL\n");
                continue;
            }
            int sss = 0;
            for (list<int>::iterator it = my_hash_map[i].begin(); it != my_hash_map[i].end(); it++) {
                if (sss == my_hash_map[i].size() - 1) printf("%d\n", *it);
                else printf("%d ", *it);
                sss++;
            }
        }
    }
    return 0;
}