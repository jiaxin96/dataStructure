#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

struct cmp
{
	bool operator ()(const string & a, const string & b) {
		if (a.length() < b.length()) return true;
		if (a.length() > b.length()) return false;
		return a < b;
	}
};

int main(int argc, char const *argv[])
{
	int t;
	std::map<string, int, cmp> v;
	while (scanf("%d", &t) != EOF) {
		v.clear();
		while(t--) {
			string temp;
			cin >> temp;
			v[temp]++;
		}
		for (std::map<string, int, cmp>::iterator it = v.begin(); it != v.end(); ++it)
		{
			cout << it->first << " " << it->second << endl;
		}
	}
	return 0;
}