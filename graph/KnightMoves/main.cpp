#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct point
{
	int r;
	int c;
	point(int rr = 0, int cc = 0) : r(rr), c(cc) {}
};
int main(int argc, char const *argv[])
{
	int map[9][9] = {{0}};
	int t;
	cin >> t;
	while (t--) {
		queue<point> q;
		int a[9][9] = {{0}};
		int dis[9][9] = {{0}};
		string s;
		string e;
		cin >> s >> e;

		point startP(s[1] - '0', s[0] - 'a' + 1);
		point endP(e[1] - '0', e[0] - 'a' + 1);
		a[startP.r][startP.c] = 1;
		q.push(startP);
		int length = 0;

		while (q.size()) {
			point temp = q.front();
			if (temp.r == endP.r && temp.c == endP.c) break;
			q.pop();
			if ((temp.r - 1 > 0 && temp.c - 2 > 0) && !a[temp.r - 1][temp.c - 2]) {
				a[temp.r - 1][temp.c - 2] = 1;
				dis[temp.r - 1][temp.c - 2] = dis[temp.r][temp.c] + 1;
				q.push(point(temp.r - 1, temp.c - 2));
			}
			if (temp.r - 2 > 0 && temp.c - 1 > 0 && (!a[temp.r - 2][temp.c - 1])) {
				a[temp.r - 2][temp.c - 1] = 1;
				dis[temp.r - 2][temp.c - 1] = dis[temp.r][temp.c] + 1;
				q.push(point(temp.r - 2, temp.c - 1));
			}
			if (temp.r - 2 > 0 && temp.c + 1 < 9 && !a[temp.r - 2][temp.c + 1]) {
				a[temp.r - 2][temp.c + 1] = 1;
				dis[temp.r - 2][temp.c + 1] = dis[temp.r][temp.c] + 1;
				q.push(point(temp.r - 2, temp.c + 1));
			}
			if (temp.r - 1 > 0 && temp.c + 2 < 9 && !a[temp.r - 1][temp.c + 2]) {
				a[temp.r - 1][temp.c + 2] = 1;
				dis[temp.r - 1][temp.c + 2] = dis[temp.r][temp.c] + 1;
				q.push(point(temp.r - 1, temp.c + 2));
			}
			if (temp.r + 1 < 9 && temp.c + 2 < 9 && !a[temp.r + 1][temp.c + 2]) {
				a[temp.r + 1][temp.c + 2] = 1;
				dis[temp.r + 1][temp.c + 2] = dis[temp.r][temp.c] + 1;
				q.push(point(temp.r + 1, temp.c + 2));
			}
			if (temp.r + 2 < 9 && temp.c + 1 < 9 && !a[temp.r + 2][temp.c + 1]) {
				a[temp.r + 2][temp.c + 1] = 1;
				dis[temp.r + 2][temp.c + 1] = dis[temp.r][temp.c] + 1;
				q.push(point(temp.r + 2, temp.c + 1));
			}
			if (temp.r + 2 < 9 && temp.c - 1 > 0 && !a[temp.r + 2][temp.c - 1]) {
				a[temp.r + 2][temp.c - 1] = 1;
				dis[temp.r + 2][temp.c - 1] = dis[temp.r][temp.c] + 1;
				q.push(point(temp.r + 2, temp.c - 1));
			}
			if (temp.r + 1 < 9 && temp.c - 2 > 0  && !a[temp.r + 1][temp.c - 2]) {
				a[temp.r + 1][temp.c - 2] = 1;
				dis[temp.r + 1][temp.c - 2] = dis[temp.r][temp.c] + 1;
				q.push(point(temp.r + 1, temp.c - 2));
			}
		}
		cout << "To get from " << s << " to " << e << " takes " << dis[endP.r][endP.c] << " knight moves.\n";

	}
	return 0;
}