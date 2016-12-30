#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) {
		stack<char> ss;
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
				ss.push(str[i]);
			} else if (str[i] == '}') {
				if (ss.size() && ss.top() == '{') ss.pop();
				else ss.push(str[i]);
			} else if (str[i] == ']') {
				if (ss.size() && ss.top() == '[') ss.pop();
				else ss.push(str[i]);
			} else if (str[i] == ')') {
				if (ss.size() && ss.top() == '(') ss.pop();
				else ss.push(str[i]);
			}
		}
		if (!ss.size()) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	return 0;
}