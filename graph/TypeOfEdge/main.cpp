#include <iostream>

using namespace std;
int map[101][101] = {{0}};
int visited[101] = {0};
int type[101][101] = {{0}};
bool allVisited(int dex, int n) {
	for (int i = 1; i <= n; ++i)
	{
		if (map[dex][i] && !visited[i]) return false;
	}
	return true;
}

void DFS(int dex, int n, int source) {
	visited[dex] = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (i == dex) continue;
		if (map[dex][i]) {
			if (visited[i]) {
				if (allVisited(i,n)) {
					if (dex == source) type[dex][i] = 2;
					else type[dex][i] = 3;
				} else {
					type[dex][i] = 1;
				}
			} else {
				DFS(i, n, source);
			}
		}
	}
}

int main(int argc, char const *argv[])
{

	int n, m;
	cin >> n >> m;
	while (m--) {
		int a,b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	// DFS(1, n, i);
	for (int i = 1; i <= n; ++i)
	{	
		if (!visited[i])
			DFS(i, n, i);
	}
	int t;
	cin >> t;
	/*
		edge (1,2) is Tree Edge
		edge (3,1) is Back Edge
		edge (1,3) is Down Edge
		edge (4,2) is Cross Edge
	*/
	{
		while (t--) {
			int a,b;
			cin >> a >> b;
			cout << "edge (" << a << "," << b << ") is " <<
			( (type[a][b] == 0) ? "Tree" : (type[a][b] == 1 ? "Back" : (type[a][b] == 2 ? "Down" : "Cross")) )
			<< " Edge\n";
		}
	}
	return 0;
}