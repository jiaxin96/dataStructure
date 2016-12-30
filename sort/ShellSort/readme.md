Sorting is a basic function in any databases. Assume there are N entries in the given database. Every entry has M items. To determine the order, we are first required to provide the priorities among the columns. Priorities are measured by M distinct integers. The lower integer indicates the higher priority.

To compare two entries, item in the column with highest priority is used. If equal, the items in the column with the second highest priority are compared. Then the 3rd to Nth highest column, until in which the items are not equal. If two entries are completely the same, the one given earlier in the data will rank first.

You are now given a job to implement the sorting function with different column priorities.

Input
The first integer T (≤30) indicates the number of cases. There follows T cases.

In every cases, the first line contain two integer N (≤100), M (≤10). N is the number of entries. M is the number of the column. The N lines is followed, every line contains M integers. The jth integer in the ith line correspond with the content in the ith entry jth column. Then a number Q (≤10) follows indicating the number of the queries. In every line, there are M integers. The ith number is the priority of the ith column.

Output
For every case, output Q lines. Every line contains N distinct integers (numbered from 0 to N-1) in ascending order with given priorities. Number i means the (i+1)th entry.
Sample Input
 Copy sample input to clipboard
1
6 3
1 1 1
1 2 3
2 2 4
2 2 3
3 1 2
3 2 2
4
1 2 3
0 1 2
30 20 10
0 -1 1
Sample Output
0 1 3 2 4 5
0 1 3 2 4 5
0 4 5 1 3 2
0 4 1 3 2 5