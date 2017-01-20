import java.util.*;
import java.io.*;

public class Main{
	public static final int INF = 999;
	public static void main(String[] args){
		Scanner in=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int n=in.nextInt();
		int m=in.nextInt();
		int [][] preMap=new int[n][n];
		// int [][] posMap = new int[n][n];
		for (int i = 0; i < n ; i++ ){
			for (int j = 0; j < n ; j++ ){
				preMap[i][j]=INF;
				// posMap[i][j] = INF;
			}
			preMap[i][i] = 0;
			// posMap[i][i] = 0;
		}

		for (int i = 0; i < m ; i++ ){
			int x = in.nextInt();
			int y = in.nextInt();
			preMap[x - 1][y - 1] = 1;
			// posMap[y - 1][x - 1] = 1;
		}


		for (int k=0;k< n ;k++ ){
			for (int i=0;i< n ;i++ ){
				for (int j=0;j< n ;j++ ){
					preMap[i][j]=Math.min(preMap[i][j], preMap[i][k] + preMap[k][j]);
					// posMap[i][j]=Math.min(posMap[i][j], posMap[i][k] + posMap[k][j]);
				}
			}
		}

		int count = 0;
		// boolean find = false;
		for (int i = 0; i < n; ++i) {
			int num = 0;
			for (int j = 0; j < n; ++j) {
				if (preMap[i][j] < INF || preMap[j][i] < INF) {
					num++;
				}
			}
			if (num == n) {
				count++;
			}
		}

		System.out.println(count);
	}
}