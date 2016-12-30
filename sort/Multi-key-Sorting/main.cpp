#include <iostream>
#include <list>
#include <cstring>
#include <cstdio>
using namespace std;
bool visit[1000000];
int a[3000000];
int ans[1000000];
void Mclear() {
	memset(visit, 0, sizeof(visit));
}

int main(int argc, char const *argv[])
{
	int c, n;
	while (scanf("%d%d", &c, &n) != EOF) {

		Mclear();
		// list<int> ans;

		int k = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}


		for (int i = n - 1; i >= 0; --i)
		{
			if (!visit[a[i]]) {
				visit[a[i]] = 1;
				ans[k++] = a[i];
			}
		}


		cout << k << endl;
	// copy(ans.begin(), ans.end(), ostream_iterator<int> (cout, " "));
		int count = 0;
		// for (list<int>::iterator it = ans.begin(); it != ans.end(); ++it, count++)
		// {
		// 	if (count == ans.size() - 1) cout << *it << endl;
		// 	else cout << *it << " ";
		// }
		for (int i = k - 1; i >= 0; --i)
		{
			if (i == 0) cout << ans[i] << endl;
			else cout << ans[i] << " ";
			/* code */
		}
	}
	return 0;
}