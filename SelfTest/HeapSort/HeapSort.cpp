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

void swap(int *a, int n, int b) {
	int t = a[n];
	a[n] = a[b];
	a[b] = t;
}

void Hsort(int *a, int  n) {
	for (int i = n/2; i >= 0; --i)
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
	int a[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	Hsort(a, n);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}