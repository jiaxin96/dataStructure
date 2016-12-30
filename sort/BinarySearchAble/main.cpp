#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	freopen("data", "r", stdin);
	int n;  
	while (cin >> n) {  
		int a[105];
		for (int i = 0; i < n; i++) {  
			cin >> a[i];  
		}  
		int count = 0;
		bool left, dext;
		for (int i = 0; i < n; i++) {
			left = dext = true;  
			for (int j = i + 1; j < n; j++) {  
				if (a[i] > a[j]) {  
					dext = false;  
					break;  
				}  
			}  
			for (int j = i - 1; j >= 0; j--) {  
				if (a[i] < a[j]) {  
					left = false;  
					break;  
				}  
			}  
			if (left && dext) {  
				count++;  
			}  
		}  
		cout << count << endl;  
	}  
}       