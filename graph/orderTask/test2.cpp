#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<math.h>  
#define max 100+5  
int c[max],topo[max],t,n,G[max][max];  
int dfs(int u)  
{  
    int v;  
    c[u] = -1;  
    for(v = 1; v <= n; v++)  
        if(G[u][v])  
        {
            if(c[v] < 0) return 0;  
            else if(!c[v] && !dfs(v)) return 0;  
        }  
    c[u] = 1;  
    topo[--t] = u;  
    return 1;  
}  
int toposort()  
{  
    int i;  
    t = n;  
    memset(c,0,sizeof(c));  
    for(i = 1; i <= n; i++)  
        if(!c[i] && !dfs(i))  
                return 0;
    return  1;  
}  
int main()  
{  
#ifdef state  
    freopen("sample.txt","r",stdin);  
#endif  
    int m,i,t;
    scanf("%d", &t);  
    while(t--)  
    { 
        scanf("%d%d",&n,&m);
        int u,v;  
        memset(G,0,sizeof(G));  
        for(i = 0 ; i < m ; i++)  
        {  
            scanf("%d%d",&u,&v);  
            G[u][v] = 1;  
        }  
        if(toposort())  
        {  
            for(i = 0; i < n-1; i++)  
                printf("%d ",topo[i]);  
            printf("%d\n",topo[i]);  
        }  
    }  
    return 0;  
}  