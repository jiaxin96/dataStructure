#include <cstdio>
using namespace std;
int main() {
	long t;
	scanf("%ld", &t);
	while (t--) {
		long a, b;
		scanf("%ld%ld", &a,&b);
		while (a != b) {
			if (a > b) a >>=1;
			else b>>=1;
		}
		printf("%ld\n", a);
	}
	return 0;
}