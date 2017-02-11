#include <iostream>
#include <string>
using namespace std;
#define max_sze 100

void getNext(int *next, string & sstr) {
	next[0] = -1;
	int k = -1;
	cout << sstr.length() << endl;
	for (int i = 1; i < sstr.length(); ++i)
	{
		while (k >= 0 && sstr[i] != sstr[k + 1]) k = next[k];
		if (sstr[i] == sstr[k+1]) k++;
		next[i] = k;
	}
	cout << "   ^&*   " << next[0];
}


int com(string & mstr, string & sstr, int * next) {
	int p = -1;
	for (int i = 0; i < mstr.length(); ++i)
	{
		while (p >= 0 && sstr[p + 1] != mstr[i]) {
			p = next[p];
		}
		if (mstr[i] == sstr[p + 1]) {
			p++;
		}
		if (p == sstr.length() - 1) {
			return i - (sstr.length() - 1);
		}
	}
	return -1;
}


int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) {
		string mstr;
		cin >> mstr;
		string sstr;
		cin >> sstr;
		int next[max_sze];
		getNext(next, sstr);
		cout << com(mstr, sstr, next) << endl;
		int pos = com(mstr, sstr, next);
	}
	return 0;
}