#include <iostream>
#include <cstring>
using namespace std;
bool visit[10000000];
const long sizemove = 5000000;
struct node
{
	int data;
	node * lc;
	node * rc;
	node(int d = 0, node * l = NULL, node * r = NULL) : data(d), lc(l), rc(r) {}
};


void insert(node * root) {}

int getIndex(int *a, int num, int n) {
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == num) return i;
	}
	return -1;
}
void bulid(int *pre, int *in, node *root, int key, int sizea, int s, int e) {
	int l = 0, r = 0;
	int posl;
	int posr;
	for (int i = s; i <= e; ++i)
	{
		int index = getIndex(pre, in[i], sizea);
		if (!visit[pre[index] + sizemove]) {
			visit[pre[index] + sizemove] = true;
			int pos = getIndex(in, in[i], sizea);
			if (pos > key) {
				root->rc = new node(in[i]);
				posr = pos;
				r = 1;
			} else if (pos < key) {
				root->lc = new node(in[i]);
				posl = pos;
				l = 1;
			}
		}
		if (r && l) break;
	}
	if (key - 1 > s)
	bulid(pre, in, root->lc, posl, sizea, s, key - 1);
	if (key + 1 < e)
	bulid(pre, in, root->rc, posr, sizea, key + 1, e);
}

int getH(node *root) {
	if (!root) return 0;
	int i = getH(root->lc);
	int j = getH(root->rc);
	return (i > j ? i + 1 : j + 1);
}

int getLevel(int * pre, int *in, int kpos, int spos, int epos, int n) {
	int lh = 0, rh = 0;
	bool l = false, r = false;
	for (int i = 0; i < n; ++i)
	{
		int cc = getIndex(in, pre[i], n);
		if (cc>= spos && cc <= epos) {
			if (cc < kpos) {
				if (!l) lh = getLevel(pre, in, cc, spos, kpos-1,n);
				l = true;
			} else if (cc > kpos) {
				if (!r) rh = getLevel(pre, in, cc, kpos + 1,  epos, n);
				r = true;
			}
		}
	}
	return (lh > rh ? lh +1 : rh + 1);
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) {
		memset(visit, 0, sizeof(visit));
		int n;
		cin >> n;
		int * pre = new int[n];
		int * in = new int[n];
		int * leve = new int[n];
		for (int i = 0; i < n; ++i)
		{
			int temp;
			cin >> temp;
			pre[i] = temp;
		}
		int k;
		for (int i = 0; i < n; ++i)
		{
			int temp;
			cin >> temp;
			in[i] = temp;
			if (temp == pre[0]) k = i;
		}
		cout << getLevel(pre, in, k, 0, n-1, n) - 1 << endl;
		delete [] pre;
		delete [] in;
	}
	return 0;
}