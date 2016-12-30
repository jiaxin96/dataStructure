#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	std::vector<list<int>> v(11);
	for (int i = 0; i < t; ++i)
	{
		char o;
		int num;
		cin >> o >> num;
		int k = num % 11;
		if (o == 'F') {
			int i = 0, j = 0;
			for (list<int>::iterator it = v[k].begin(); it != v[k].end(); it++) {
				if (*it == num) {
					cout << i << endl;
					j = 1;
					break;
				}
				i++;
			}
			if (j == 0) {
				cout << "-1\n";
			}
		} else {
			v[k].push_front(num);
		}
	}
	return 0;
}