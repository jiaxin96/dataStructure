#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		queue<int> q;
		for (int i = 0; i < n; ++i)
		{
			q.push(i+1);
		}
		while (q.size() >= 2) {
			cout << q.front() << " ";
			q.pop();
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << endl;
	}
	return 0;
}