#include <cstdio>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	set<long> ss;
	while (scanf("%d", &n) && n != 0) {
		ss.clear();
		set<long>::iterator it;
		for (int i = 0; i < n; ++i)
		{
			int t;
			scanf("%d", &t);
			it = ss.find(t);
			if (it == ss.end()) {
				ss.insert(t);
			} else {
				ss.erase(it);
			}
		}
		printf("%ld\n", *(ss.begin()));
	}

	return 0;
}