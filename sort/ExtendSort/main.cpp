#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string filter(string temp) {
	int l = temp.length();
	string ans = "";
	for (int i = 0; i < l; ++i)
	{
		if (temp[i]>='a' && temp[i]<='z') {
			temp[i] = temp[i] - 'a' + 'A';
			ans += temp[i];
			continue;
		}
		if (temp[i]=='+' || temp[i] == '-') {
			continue;
		}
		if (temp[i]=='0') {
			for (int j = i+1; j < l; ++j)
			{
				if (temp[j] == '0') continue;
				else {
					i = j;
					ans += temp[i];
					break;
				}
			}
			continue;
		}
		ans += temp[i];
	}
	return ans;
}
int com(string & s1, string & s2) {
	if (s1.length() > s2.length()) {
		return 1;
	} else if (s1.length() < s2.length()) {
		return -1;
	} else {
		if (s1 > s2) {
			return 1;
		} else if (s1 < s2) {
			return -1;
		} else {
			return 0;
		}
	}
}
int main(int argc, char const *argv[])
{
	freopen("data", "r", stdin);
	int n;
	cin >> n;
	int tn = n;
	while(n--) {
		string s1, s2;
		cin >> s1 >> s2;
		s1 = filter(s1);
		s2 = filter(s2);
		cout << s1 << " " << s2 << endl;
		cout << tn - n << " ";
		if (com(s1,s2) > 0) {
			cout << "1\n";
		} else if (com(s1,s2) < 0) {
			cout << "-1\n";
		} else {
			cout << "0\n";
		}
	}
	return 0;
}