#include <iostream>
#include <string>
using namespace std;
#define max_sze 100

void getNext(int *next, string & str) {
	next[0] = -1;
	int k = -1;
	for (int i = 1; i < str.length(); ++i)
	{
		while (k >= 0 && str[i] != str[k + 1]) k = next[k];
		if (str[i] == str[k+1]) k++;
		next[i] = k;
	}
}


int com(string & mstr, string & str, int * next) {
	
}


int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) {
		string mstr;
		cin >> mstr;
		string str;
		cin >> str;
		int next[max_sze];
		getNext(next, str);
		int pos = com(mstr, str, next);
	}
	return 0;
}