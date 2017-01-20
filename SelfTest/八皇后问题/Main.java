public class Main {

	private static int [][] World = new int[8][8];


	public static void main(String[] args) {
		solve();
	}

	public static void solve() {
		clearMap();
		for (int i = 0; i < 8; ++i) {
			World[0][i] = 1;
			getans(1, 0,i);
			World[0][i] = 0;
		}
	}

	public static void getans(int num, int r, int c) {
		if (num == 8) {
			printMap();
			return;
		}
		for (int i = 0; i < 8; i++) {
			if (r + 1 < 8 && canplace(r + 1, i)) {
				World[r + 1][i] = 1;
				getans(num + 1, r + 1, i);
				World[r + 1][i] = 0;
			}
		}
	}

	public static boolean canplace(int r, int c) {
		int tr = r, tc = c;
		for (int i = 0; i < 8; ++i) {
			if (World[r][i] == 1) return false;
		}
		for (int i = 0; i < 8; ++i) {
			if (World[i][c] == 1) return false;
		}
		for (int i = r + 1; i < 8; ++i) {
			tc++;
			if (tc >= 8) break;
			if (World[i][tc] == 1) return false;
		}
		tc = c;
		for (int i = r - 1; i >= 0; --i) {
			tc--;
			if (tc < 0) break;
			if (World[i][tc] == 1) return false;
		}
		tc = c;
		for (int i = r + 1; i < 8; ++i) {
			tc--;
			if (tc < 0) break;
			if (World[i][tc] == 1) return false;
		}
		tc = c;

		for (int i = r - 1; i >= 0; --i) {
			tc++;
			if (tc >= 8) break;
			if (World[i][tc] == 1) return false;
		}
		return true;
	}

	public static void clearMap() {
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				World[i][j] = 0;
			}
		}
	}

	static int numAns = 1;
	
	public static void printMap() {
		System.out.printf("No.%d\n", numAns++);
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				System.out.printf("%d ", World[j][i]);
			}
			System.out.printf("\n");
		}
	}
}