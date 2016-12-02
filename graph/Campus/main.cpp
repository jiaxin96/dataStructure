#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;
int MAP[105][105];
struct edge
{
	string p1;
	string p2;
	int length;
	edge(string pp1, string pp2, int l) :
	p1(pp1), p2(pp2), length(l) {}
};

struct point
{
	string name;
	int d;
	string pi;
	int id;
	point(string n, int dd = 200) : name(n), d(dd) {}
};



struct MyCom
{
        bool operator () (const point & x, const point & y) const
        {
                if (x.d < y.d)
                        return true;
                else
                        return false;
        }
};

void init() {
	for (int i = 0; i < 105; ++i)
	{
		for (int j = 0; j < 105; ++j)
		{
			MAP[i][j] = 200;
		}
	}
}
int findMin(int n) {
	int ans = -1;
	int mai = 200;
	for (int i = 1; i < 105; ++i) {
		if (mai > MAP[n][i]) {
			mai = MAP[n][i];
			ans = i;
		}
	}
	return ans;
}
void updataMap(int s, int m) {
	
}
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) {
		init();
		int n;
		cin >> n;
		map<string, int> pp;
		std::vector<edge> v;
		int idd = 1;
		for (int i = 0; i < n; ++i) {
			string s1, s2;
			int ll;
			cin >> s1 >> s2 >> ll;
			if (pp.find(s1) == pp.end()) {
				pp[s1] = idd++;
			}
			if (pp.find(s2) == pp.end()) {
				pp[s2] = idd++;
			}
			MAP[pp[s1]][pp[s2]] = (MAP[pp[s1]][pp[s2]] <= ll) ? MAP[pp[s1]][pp[s2]] : ll;
			MAP[pp[s2]][pp[s1]] = (MAP[pp[s2]][pp[s1]] <= ll) ? MAP[pp[s2]][pp[s1]] : ll;
		}
		string startPoint, endPoint;
		cin >> startPoint >> endPoint;
		if (pp.find(startPoint) == pp.end() || pp.find(endPoint) == pp.end()) {
			cout << "-1\n";
			continue;
		} else if (startPoint == endPoint) {
			cout << "0\n";
			continue;
		}
		int sp = pp[startPoint], ep = pp[endPoint];
		set<int> visitedPoint;
		visitedPoint.insert(sp);
		int temp = sp;
		while (visitedPoint.size() == idd - 1) {
			temp = findMin(temp);
			if (temp == -1) break;
			updataMap(sp, temp);
		}
	}
	return 0;
}