#include <cstdio>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	bool flag = true;
	while(scanf("%d", &n) != EOF) {
		if (flag) {
			flag = false;
		} else {
			printf("\n");
		}
		std::map<long, int> m;
		for (int i = 0; i < n; ++i)
		{
			long temp;
			scanf("%ld",&temp);
			m[temp]++;
		}
		for (std::map<long, int>::iterator it = m.begin();it != m.end();  ++it) {
			printf("%ld %d\n", (*it).first, (*it).second);
		}
	}
	return 0;
}