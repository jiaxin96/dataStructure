#include <iostream>
#include <cstring>
const int inf = 99999;
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) {
		int n, m, v1, v2;
		cin >> n >> m >> v1 >> v2;
		int **map = new int*[n];
		for (int i = 0; i < n; ++i)
		{
			map[i] = new int[n];
			for (int j = 0; j < n; ++j)
			{
				map[i][j] = inf;
			}
		}
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			map[a][b] = 1;
			map[b][a] = 1;
		}
		for (int k = 0; k < n; ++k)
		{
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (map[i][j] > map[i][k] + map[k][j]) {
						map[i][j] = map[i][k]+map[k][j];
					}
				}
			}
		}
		cout << map[v1][v2] << endl;
	}
	return 0;
}