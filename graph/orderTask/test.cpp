#include<stdio.h>  
#include<string.h>  
#define N 2505  
long m, n, cnt;  
long map[N][N], bo[N];  

long judge(long k){  
    for (long i = 1; i <= n; i++)  
        if (map[k][i])  
         return 0;  
    return 1;  
}  

long clear(long k){  
    for (long i = 1; i <= n; i++)  
        map[i][k] = 0;
    return 0;
}

int main(){
    long t;
    scanf("%ld", &t);
    while (t--){
    scanf("%ld%ld", &n, &m);
    // Init.  
        memset(map, 0, sizeof(map));  
        memset(bo, 0, sizeof(bo));  
        cnt = 0;  

    // Read.  
        for (long i = 0; i < m; i++){  
            long a, b;   
            scanf("%ld%ld", &a, &b);  
            map[b][a] = 1;  
        }  

    // Handle.  
        while (cnt < n){  
            for (long i = 1; i <= n; i++){  
                if (bo[i])  continue;  
                if (judge(i)){  
                    if (cnt)  
                        printf(" ");
                    printf("%ld", i);  
                    bo[i] = 1;  
                    cnt++;  
                    clear(i);  
                    break;  
                }  
            }  
        }  
        printf("\n");  
    }  
    return 0;
} 