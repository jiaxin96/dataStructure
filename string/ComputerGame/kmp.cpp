#include <cstdio>
#include <cstring>
using namespace std;
#include <iostream>
int main(int argc, char const *argv[]) {
  int n;
  int m;
  int aim[60005] = {0};
  int next[60005] = {0};
  int fix[100005] = {0};
  while (scanf("%d", &n) != EOF) {
    bool finAns = false;
    for (int i = 1; i <= n; ++i) {
      scanf("%d ", &aim[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &fix[i]);
    }
    {
      next[1]=0;
      int j=0;
      for(int i=2;i<=n;++i)
      {
          while(j>0 && aim[j+1]!=aim[i])
              j=next[j];
          if(aim[j+1]==aim[i])
              j=j+1;
          next[i]=j;
      }
    }
    {
        int j=0;
        for(int i=1;i <= m;++i)
        {
            while(j > 0 && aim[j+1]!=fix[i])
                j=next[j];
            if(aim[j+1]==fix[i])
                j=j+1;
            if(j==n)
            {
                printf("%d\n",i-n);
                finAns = true;
                break;
            }
        }
        if (!finAns)
          printf("no solution\n");
    }
  }
  return 0;
}
