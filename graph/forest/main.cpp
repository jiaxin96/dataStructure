#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int maxof(int *a, int n) {
	int max = 0;
	for (int i = 0; i < n; ++i) {
		max = (max > a[i] ? max : a[i]);
	}
	return max;
}

int main(int argc, char const *argv[])
{	
	int n ,m;

	cin >> n >> m;
	while (n != 0) {
		int  **v = new int*[n+1];
		int  *visited = new int[n+1];
		int  *dis = new int[n+1];
		int deep = 0;
		int *width = new int[n+1];
		std::vector<int> root;
		for (int i = 0; i < n+1; ++i)
		{			
			visited[i] = 0;
			dis[i] = 0;
			v[i] = new int[n+1];
			width[i] = 0;
			for (int j = 0; j < n+1; ++j) {
				v[i][j] = 0;
			}
		}

		bool end = false;
		while (m--) {
			int a, b;
			cin >> a >> b;
			if (a == b) end = true;
			v[a][b] = 1;
		}

		bool flag = true;
		for (int i = 1; i <= n; ++i) {
			flag = true;
			for (int j = 1; j <= n; ++j)
			{
				if (v[j][i] == 1) flag = false;
			}
			if (flag) {
				root.push_back(i);
			}
		}


		for (int k = 0; k < root.size(); ++k)
		{
			int i = root[k];
			queue<int> q;
			if (!visited[i]) {
				q.push(i);
				visited[i] = 1;
				width[0]++;
			} else {
				continue;
			}

			while (q.size()) {
				int f = q.front();
				q.pop();
				for (int j = 1; j <= n; ++j) {
					if (!visited[j] && v[f][j]) {
						q.push(j);
						visited[j] = 1;
						dis[j] = dis[f] + 1;
						deep = (deep > dis[j]) ? deep : dis[j];
						width[dis[j]]++;
					} else if (v[f][j] && visited[j]) {
						end = true;
						break;
					}
				}
				if (end) break;
			}
		}
		if (!end && root.size()) {
			cout << deep << " " << maxof(width, n) << endl;
		} else {
			cout << "INVALID\n";
		}

		for (int i = 0; i < n+1; ++i) {
			delete [] v[i];
		}
		delete [] v;
		delete [] visited;
		delete [] dis;
		delete [] width;
		cin >> n >> m;

	}
	return 0;
}