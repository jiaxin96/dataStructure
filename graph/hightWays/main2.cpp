#include <cstdio>
#include <set>
using namespace std;


struct edge
{
	int p1;
	int p2;
	int weight;
	edge(int pp1, int pp2, int w) : p1(pp1), p2(pp2), weight(w) {}
};


struct MyCom
{
        bool operator () (const edge & x, const edge & y) const
        {
                if (x.weight < y.weight)
                        return true;
                else
                        return false;
        }
};

int find_set(int v, int *a) {
	if (a[v] != v) return find_set(a[v], a);
	else return v;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int *v = new int[n + 1];
		for (int i = 0; i < n + 1; ++i) {
			v[i] = i;
		}
		set<edge, MyCom> ee;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				int ww;
				scanf("%d", &ww);
				ee.insert(edge(i, j, ww));
			}
		}
		int max = 0;
		for (set<edge, MyCom>::iterator it = ee.begin(); it != ee.end(); ++it) {
			int x = find_set((*it).p2, v);
			int y = find_set((*it).p1, v);
			if (x != y) {
				v[x] = y;
				max = (max >= (*it).weight) ? max : (*it).weight;
			}
		}
		printf("%d\n", max);
		delete [] v;
	}
	return 0;
}

