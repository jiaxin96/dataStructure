#include <cstdio>
#include <vector>
#include <set>
#include <list>
using namespace std;
void DFS(vector< set<int, greater<int> > > &mm, vector<int> & visit, int num, list<int> & ans);

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector< set<int, greater<int> > > mm(n+1);
		vector<int> visit(n+1, 0);
		list<int> ans;
		int p1,p2;
		for (size_t i = 0; i < m; i++)
		{
			scanf("%d%d", &p1, &p2);
			mm[p1].insert(p2);
		}
		for (size_t i = n; i >= 1; i--)
		{
			if (mm[i].empty())
			{
				if (visit[i] > 0) continue;
				else
				{
					visit[i]++;
					ans.push_front(i);
				}
			}
			else
			{
				if (!visit[i]) {
					visit[i]++;
					DFS(mm, visit, i, ans);
				}
			}
		}
		for (list<int>::iterator it = ans.begin(); it != ans.end(); it++)
		{
			printf("%d ", *it);
		}
		printf("\n");
	}
	return 0;
}
void DFS(vector< set<int, greater<int> > > &mm, vector<int> & visit, int num, list<int> & ans) {
	for (set<int, greater<int> >::iterator it = mm[num].begin(); it != mm[num].end(); it++)
	{
		if (!visit[*it]) {
			visit[*it]++;
			DFS(mm, visit, *it, ans);
		}
	}
	ans.push_front(num);
}











