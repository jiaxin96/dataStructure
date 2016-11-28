#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int x, y;
		cin >> x >> y;
		if (x== 1 || y == 1) {
			cout << "1\n";
			continue;
		}
		int X[11] = {0};
		int Y[11] = {0};
		int cx = 0, cy = 0;
		while(x != 1) {
			x = x>>1;
			X[cx] = (x);
			cx++;
		}

		while(y != 1) {
			y = y>>1;
			Y[cy] = (y);
			cy++;
		}
		cy--;
		cx--;
		while(cx >=0 && cy >= 0) {
			if (Y[cy] != X[cx]) {
				break;
			}
			cy--;
			cx--;
		}
		cout << Y[cy+1] << endl;
	}
	return 0; 
}
