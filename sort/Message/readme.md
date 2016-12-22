
Time Limit: 1sec    Memory Limit:32MB
Description
Well, how do you feel about mobile phone? Your answer would probably be something like that “It’s so convenient and benefits people a lot”. However, if you ask Merlin this question on the New Year’s Eve, he will definitely answer “What a trouble! I have to keep my fingers moving on the phone the whole night, because I have so many greeting messages to send! ”. Yes, Merlin has such a long name list of his friends, and he would like to send a greeting message to each of them. What’s worse, Merlin has another long name list of senders that have sent message to him, and he doesn’t want to send another message to bother them (Merlin is so polite that he always replies each message he receives immediately). So, before he begins to send messages, he needs to figure to how many friends are left to be sent. Please write a program to help him. 
Here is something that you should note. First, Merlin’s friend list is not ordered, and each name is alphabetic strings and case insensitive. These names are guaranteed to be not duplicated. Second, some senders may send more than one message to Merlin, therefore the sender list may be duplicated. Third, Merlin is known by so many people, that’s why some message senders are even not included in his friend list.
Input
There are multiple test cases. In each case, at the first line there are two numbers n and m (1<=n, m<=20000), which is the number of friends and the number of messages he has received. And then there are n lines of alphabetic strings (the length of each will be less than 10), indicating the names of Merlin’s friends, one per line. After that there are m lines of alphabetic strings, which are the names of message senders.
 The input is terminated by n=0. 

Output
For each case, print one integer in one line which indicates the number of left friends he must send. 
Sample Input
 Copy sample input to clipboard
5 3
Inkfish
Henry
Carp
Max
Jericho
Carp
Max
Carp
0
Sample Output
3