	
Time Limit: 1sec    Memory Limit:32MB
Description
One of the fundamental problems of computer science is ordering a list of items. There're a plethora of solutions to this problem, known as sorting algorithms. Some sorting algorithms are simple and intuitive, such as the bubble sort. Others, such as the heap sort are not so simple, but produce lightening-fast results.
 

In the following is a list of some sorting algorithms. Of course, I can’t tell you how to implement them here. You must use your own knowledge.
Bubble sort
Heap sort
Insertion sort
Merge sort
Quick sort
Selection sort
Shell sort
…
 

My business here is to give you some numbers, and to sort them is your business. Attention, I want the smallest number at the top of the sorted list.
Input
The input file will consist of series data sets. Each data set has two parts. The first part contains two non-negative integers, n (1≤n≤100,000) and m (1≤m≤n), representing the total of numbers you will get and interval of the output sorted list. The second part contains n positive integers. I am sure that each integer in this part will be less than 2,000,000,000.
The input is terminated by a line with two zeros.
Output
For one data set, you should output several numbers in ONE line. After you get the sorted list, you should output the first number of each m numbers, and you should print exact ONE space between two adjacent numbers. And please make sure that there should NOT be any blank line between outputs of two adjacent data sets.
Sample Input
 Copy sample input to clipboard
8 2
3
5
7
1
8
6
4
2
0 0
Sample Output
1 3 5 7