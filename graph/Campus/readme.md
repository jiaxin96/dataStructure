	
Time Limit: 1sec    Memory Limit:32MB
Description
At present, Zhongshan University has 4 campuses with a total area of 6.17 square kilometers sitting respectively on both sides of the Pearl River or facing the South China Sea. The Guangzhou South Campus covers an area of 1.17 square kilometers, the North Campus covers an area of 0.39 square kilometers, the Guangzhou East Campus has an area of 1.13 square kilometers and the Zhuhai Campus covers an area of 3.48 square kilometers. All campuses have exuberance of green trees, abundance of lawns and beautiful sceneries, and are ideal for molding the temperaments, studying and doing research.

 


 

       Sometime, the professors and students have to go from one place to another place in one campus or between campuses. They want to find the shortest path between their source place S and target place T. Can you help them?
 


 

Input
The first line of the input is a positive integer C. C is the number of test cases followed. In each test case, the first line is a positive integer N (0<N<=100) that represents the number of roads. After that, N lines follow. The i-th(1<=i<=N) line contains two strings Si, Ti and one integer Di (0<=Di<=100). It means that there is a road whose length is Di between Si and Ti. Finally, there are two strings S and T, you have to find the shortest path between S and T. S, T, Si(1<=i<=N) and Ti(1<=i<=N) are all given in the following format: str_Campus.str_Place. str_Campus represents the name of the campus, and str_Place represents the place in str_Campus. str_Campus is "North", "South", "East" or "Zhuhai". str_Place is a string which has less than one hundred lowercase characters from "a-z". You can assume that there is at most one road directly between any two places.

Output
The output of the program should consist of C lines, one line for each test case. For each test case, the output is a single line containing one integer. If there is a path between S and T, output the length of the shortest path between them. Otherwise just output "-1" (without quotation mark). No redundant spaces are needed.

Sample Input
 Copy sample input to clipboard
1
2
South.xiaolitang South.xiongdelong 2
South.xiongdelong Zhuhai.liyuan 100
South.xiongdelong South.xiaolitang
Sample Output
2