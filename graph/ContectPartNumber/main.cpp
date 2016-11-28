#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int m, n;
	cin >> m >> n;
	vector< set<int> > ss;
	int sumConPOint = 0;
	while (n--) {
		int a, b;
		cin >> a >> b;
		int newPart = true;
		for (int i = 0; i < ss.size(); i++) {
			if (ss[i].find(a) != ss[i].end() || ss[i].find(b) != ss[i].end()) {
				newPart = false;
				ss[i].insert(a);
				ss[i].insert(b);
			}
		}
		if (newPart) {
			set<int> ts;
			ts.insert(a);
			ts.insert(b);
			ss.push_back(ts);
		}
	}
	for (int i = 0; i < ss.size(); ++i) {
		sumConPOint += ss[i].size();
	}
	cout << (m - sumConPOint) + ss.size() << endl;
	return 0;
}