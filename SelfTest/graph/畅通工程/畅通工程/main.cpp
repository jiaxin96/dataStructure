#include <iostream>
#include <cstdio>
using namespace std;
#define MAXCOST 0x7fffffff

int graph[105][105];


int prim(int n, int & count) {
	int lowcase[105];
	int mst[105];
	// 初始化到1的距离 此时mst中只有1
	mst[1] = 0;
	lowcase[1] = 0;
	for (int i = 2; i <= n; ++i)
	{
		lowcase[i] = graph[1][i];
		mst[i] = 1;
	}



	int minCost, minPos, sum = 0;
	count++;


	for (int i = 2; i <= n; ++i) // 循环n-1次 把所有点加入mst集合中
	{
		minCost = MAXCOST;
		minPos = 0;
		for (int j = 2; j <= n; ++j) // 从第二个开始寻找最小权值边 和对应的点
		{
			if (lowcase[j] < minCost && lowcase[j] != 0) {
				minPos = j;
				minCost = lowcase[j];
			}
		}


		if (minCost != MAXCOST) {
			sum += minCost;
			count++;
			lowcase[minPos] = 0;
		} else {
			break;
		}



		// 更新 lowcase mst
		for (int j = 2; j <= n; ++j)
		{
			if (graph[minPos][j] < lowcase[j]) {
				lowcase[j] = graph[minPos][j];
				mst[j] = minPos;
			}
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	freopen("data", "r", stdin);
	int n, m;
	while (cin >> n >> m && n != 0) {
		for (int i = 1; i <= m; i++)  
		{  
			for (int j = 1; j <= m; j++)  
			{  
				graph[i][j] = MAXCOST;  
			}  
		}
		int x, y, w;
		for (int i = 0; i < n; ++i)
		{
			cin >> x >> y >> w;
			graph[x][y] = graph[y][x] = w;
		}
		int count = 0;
		int cost = prim(m, count);
		if (count != m) {
			cout << "?\n";
		} else {
			cout << cost << endl;
		}
	}
	return 0;
}