#include <cstdio>
#define SIDE_MOVE 10000000
#define MY_MAX_NUM 20000002

bool num[MY_MAX_NUM];

int main(int argc, char const *argv[])
{	
	for (int i = 0; i < MY_MAX_NUM; ++i) {
		num[i] = false;
	}
	int n;
	scanf("%d", &n);
	int k;
	scanf("%d", &k);
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		scanf("%d",&temp);
		if (!num[temp+SIDE_MOVE]) {
			num[temp+SIDE_MOVE] = true;
			count++;
		}
	}
	int ss = 1;
	for (int i = 0; i < MY_MAX_NUM; ++i)
	{
		if (num[i]) {
			if (ss != count+1-k) ss++;
			else {
				printf("%d\n", i - SIDE_MOVE);
				break;
			}
		}
	}
	
	return 0;
}