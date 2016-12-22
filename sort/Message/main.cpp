#include <iostream>
#include <string>
#include <set>
using namespace std;

void lowcase(string & s) {
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = s[i] - 'A' + 'a';
		}
	}
}

int main(int argc, char const *argv[])
{
	int n, m;
	set<string> fir;
	set<string>::iterator it;
	while (cin >> n && n != 0) {
		fir.clear();
		cin >> m;
		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			lowcase(str);
			fir.insert(str);
		}
		for (int i = 0; i < m; ++i)
		{
			string str;
			cin >> str;
			lowcase(str);
			it = fir.find(str);
			if (it != fir.end()) {
				fir.erase(it);
			}
		}
		cout << fir.size() << endl;
	}
	return 0;
}