#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	int *a = new int[m];
	for (int i = 0; i < m; ++i)
	{
		a[i] = -1;
	}
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		
		int k = num % m;
		if (a[k] != -1) {
			int tk = (k + 1) % m;
			while (a[tk] != -1 && tk != k) {
				tk = (tk+1) % m;
			}
			if (tk != k) a[tk] = num;
		} else {
			a[k] = num;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		if (a[i] != -1) {
			cout << i << "#" << a[i] << endl;
		} else {
			cout << i << "#NULL\n";
		}
	}
	return 0;
}