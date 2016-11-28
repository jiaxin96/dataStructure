#include <iostream>
#include <queue>
using namespace std;
int map[1005][1005] = {{0}};
int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	int *a = new int[n+1];
	int *visited = new int[n+1];
	for (int i = 0; i < n+1; ++i) {
		a[i] = -1;
		visited[i] = 0;
	}

	queue<int> q;
	q.push(1);
	a[1] = 0;
	visited[1] = 1;
	while(q.size()) {
		int f = q.front();
		q.pop();
		for (int i = 0; i <= n; ++i) {
			if(map[f][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = 1;
				a[i] = a[f] + 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	delete [] a;
	delete [] visited;
	return 0;
}