#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
	int s;
	int e;
	int weight;
	point(int ss, int ee, int w) : s(ss), e(ee), weight(w) {}
};
bool com(point a, point b) {
	return (a.weight < b.weight);
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		std::vector<point> v;
		std::vector<int> ans;
		set<int> filter;
		int **a = new int*[n + 1];
		for (int i = 0; i < n + 1; ++i) {
			a[i] = new int[n + 1];
		}
		for (int i = 1; i < n + 1; ++i) {
			for (int j = 1; j < n + 1; ++j)
			{
				scanf("%d", &a[i][j]);
				if (j > i) {
					v.push_back(point(i, j, a[i][j]));
				}
			}
		}
		sort(v.begin(), v.end(), com);
		int coun = 0;
		while (filter.size() != n) {
			if (filter.find(v[coun].s) != filter.end() && filter.find(v[coun].e) != filter.end()) {
			} else {
				filter.insert(v[coun].s);
				filter.insert(v[coun].e);
			}
			coun++;
		}
		for (int i = 0; i < n + 1; ++i) {
			delete [] a[i];
		}
		delete [] a;
	}
	return 0;
}