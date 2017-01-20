import java.util.*;
import java.io.*;

public class Solution{
	public static void main(String[] args){
		Scanner in=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int n=in.nextInt();
		int m=in.nextInt();
		int[][] p=new int[n][n];
		for (int i=0;i< n ;i++ ){
			for (int j=0;j< n ;j++ ){
				p[i][j]=101;
			}
			p[i][i]=0;
		}
		for (int i=0;i< m ;i++ ){
			p[in.nextInt()-1][in.nextInt()-1]=1;
		}
		for (int k=0;k< n ;k++ ){
			for (int i=0;i< n ;i++ ){
				for (int j=0;j< n ;j++ ){
					p[i][j]=getMin(p[i][j],p[i][k]+p[k][j]);
				}
			}
		}
		int w=0;
		for (int i=0;i< n ;i++ ){
			int t=0;
			for (int j=0;j< n ;j++ ){
				if (p[i][j]< 101||p[j][i]< 101){
					t++;
				}
			}
			if (t==n){
				w++;
			}
		}
		System.out.println(w);
	}

	public static int getMin(int a,int b){
		if (a>=b){
			return b;
		}
		else{
			return a;
		}
	}
}