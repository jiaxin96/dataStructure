#include <cstdio>
using namespace std;
#include <hash_set>
using namespace __gnu_cxx;
int f[1000005];

int find(int x){
	if(f[x]!=x) return find(f[x]);
	else return x;
}

int main(){
	int a,b;
	hash_set<int> ss;
	for(int i = 0;i < 1000005; ++i) f[i]=i;
	while(scanf("%d%d",&a,&b) != EOF){
		if (ss.find(a) != ss.end() && ss.find(b) != ss.end()) {
			continue;
		}
		int x = find(a);
		int y = find(b);
		if(x!=y){
			f[x]=y;
			printf("%d %d\n",a,b);
		} else {
			ss.insert(a);
			ss.insert(b);
		}
	} 
	
	return 0;
}