#include <iostream>

using namespace std;

void swap(int *a, int n, int b) {
	int t = a[n];
	a[n] = a[b];
	a[b] = t;
}

void splitSort(int * a, int strat, int end) {
	if (strat >= end) return;    // ###和递归试有关 > 的时候进入start i-1  =的时候进入start i
	int key = a[strat];
	int i = strat;
	int j = end;
	//                     i+1
	//         (<key)     key       (>= key)
	// 6 6 2 6 6
	while(i < j)
	{
         //顺序很重要，要先从右边开始找 
		while(a[j] >= key && i<j)
			j--;
         //再找右边的
		while(a[i] < key && i<j)
			i++;
         //交换两个数在数组中的位置
		if(i<j)
		{
			swap(a, i, j);
		}
	}

	splitSort(a, strat, i); // ###
	splitSort(a, i+1, end);
}

void Qsort(int * a, int n) {
	splitSort(a, 0, n - 1);
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		Qsort(a, n);
		for (int i = 0; i < n; ++i)
		{
			cout << a[i] << endl;
		}
	}
	return 0;
}