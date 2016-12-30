#include <iostream>

using namespace std;

void init(int *a, int  root, int  n) {
	int parent = a[root];
	// firstly get left child index
	int childIndex = 2*root + 1;
	while (childIndex < n) {

		// get the max child
		if (childIndex + 1 < n && a[childIndex] < a[childIndex + 1]) {
			childIndex++;
		}

		if (parent >= a[childIndex]) break;

		a[root] = a[childIndex];
		root = childIndex;
		childIndex = 2*childIndex + 1;
	}
	a[root] = parent;
}

void swap(int *a, int i, int j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void Hsort(int *a, int  n) {
	for (int i = (n - 1)/2; i >= 0; --i)
	{
		init(a, i, n);
	}

	for (int i = n - 1; i > 0; --i)
	{
		swap(a, i, 0);
		init(a, 0, i);
	}

}

int main(int argc, char const *argv[])
{
	int n, m;
	while (cin >> n >> m && n != 0 & m != 0) {
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		Hsort(a, n);

		for (int i = 0; i < n; i += m)
		{
			if (i > n -1 -m) cout << a[i] << endl;
			else cout << a[i] << " ";
		}
	}
	return 0;
}