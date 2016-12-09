// Problem#: 19169
// Submission#: 4939373
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
#include<queue>
#include<vector>
#include<memory.h>
using namespace std;

int indeg[100001]; 
vector<int> nodes[1000001]; 


int main()
{

    int T;
    int n,m;
    scanf("%d",&T);
    while(T--){
        memset(indeg,0,sizeof(indeg));
        scanf("%d%d",&n,&m);
        while(m--){
            int x,y;
            scanf("%d%d",&x,&y);
            nodes[x].push_back(y);
            indeg[y]++;
        }

        priority_queue<int,vector<int>,greater<int> > q; 
        for(int i=1;i<=n;i++){
            if(indeg[i]==0){
                q.push(i);
            }   
        }


        while(!q.empty()){
            int temp=q.top();
            q.pop();
            printf("%d ",temp);
            for(int i=0;i<nodes[temp].size();i++){
                indeg[nodes[temp][i]]--;
                if(indeg[nodes[temp][i]]==0){
                    q.push(nodes[temp][i]);
                }
            }   
        }       
        for(int i=0;i<n;i++){
            nodes[i].clear();

        }
        printf("\n");
    }
    return 0;
}                                 