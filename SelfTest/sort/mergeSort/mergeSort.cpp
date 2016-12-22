#include <iostream>

using namespace std;

void merge(int *a, int pre, int pos, int *sorted) {
	int mid = (pre + pos) / 2;
	int i = pre, j = mid + 1, k = pre;
	
	while (i <= mid && j <= pos) {
		if (a[i] <= a[j]) {
			sorted[k++] = a[i++];
		} else {
			sorted[k++] = a[j++];
		}
	}

	while (i <= mid) {
		sorted[k++] = a[i++];
	}

	while (j <= pos) {
		sorted[k++] = a[j++];
	}

	for (int i = pre; i <= pos; ++i)
	{
		a[i] = sorted[i];
	}
}

void splitAndSort(int *a, int pre, int pos, int * sorted) {

	if (pos - pre <= 0) {
		return;
	}
	splitAndSort(a, pre, (pre+pos)/2, sorted);
	splitAndSort(a, (pre+pos)/2 + 1, pos, sorted);
	merge(a, pre, pos, sorted);
}

void Msort(int *a, int n, int * sorted) {
	splitAndSort(a, 0, n - 1, sorted);
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		int sorted[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		Msort(a, n, sorted);
		for (int i = 0; i < n; ++i)
		{
			cout << a[i] << endl;
		}
	}
	return 0;
}