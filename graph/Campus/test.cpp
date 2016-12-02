
#include<iostream>  
#include<cstdio>  
#include<string>  
#include<map>  
#define INF 100000
#define get_min(a,b) ((a)<(b)?(a):(b))  
using namespace std;  
  
map<string,int> c;  
int g[201][201];  
  
void DJ(int n)  
{  
    for (int k = 1; k <= n; k++)  
        for (int i = 1; i <= n; i++)  
            if (g[i][k] < INF)  
                for (int j = 1; j <= n; j++)  
                    if (g[k][j] < INF)  
                        g[i][j] = get_min(g[i][j], g[i][k] + g[k][j]);
}  
int main()  
{  
    int C;  
    cin>>C;  
    while(C--)  
    {  
        for(int i=1;i<=200;i++)  
            for(int j=1;j<=200;j++)  
                if(i!=j) g[i][j]=INF;  
                else g[i][j]=0;
        int N,cnt=0;  
        cin>>N;  
        c.clear();  
        for(int i=1;i<=N;i++)  
        {  
            int v1,v2,dis;  
            string str1,str2;  
            cin>>str1>>str2>>dis;  
            if(c.find(str1)==c.end())  
                c.insert(make_pair(str1,++cnt));  
            if(c.find(str2)==c.end())  
                c.insert(make_pair(str2,++cnt));  
            v1=c[str1];  
            v2=c[str2];  
            g[v1][v2]=g[v2][v1]=dis;  
        }  
        DJ(cnt);  
        string S,T;  
        cin>>S>>T;  
        if(S==T) cout<<0<<endl;  
        else if(c.find(S)==c.end()||c.find(T)==c.end()) cout<<-1<<endl;  
        else  
        {  
            int v1=c[S],v2=c[T];  
            if(g[v1][v2]>=INF) cout<<-1<<endl;  
            else cout<<g[v1][v2]<<endl;  
        }  
    }  
    return 0;  
}  