/*
Time Limit: 1sec    Memory Limit:256MB
Description
来自USA的Mr.Allison是某班的英语老师，学期开始之前他要求自己班的同学阅读一本英文小说，并写一份50000字的读书报告。该班的同学很苦恼，并想方设法让Mr.Allison放弃读书笔记这个念头，于是该班的大牛PYY想到一个借口：看那么多份读书笔记会花费很多时间的！把这个理由告诉Mr.Allison之后，Mr.Allison也觉得挺有道理，但一共要阅读多少文字呢？于是PYY就给出一条后缀表达式，并告诉Mr.Allison说，这条表达式的结果就是您要阅读的文字。Mr.Allison的数学不咋地，于是就找你来帮他计算这条后缀表达式的值。

Input
第一行是一整数，即测试样例个数T.

以下T行，每一行是一个长度不超过100的字符串，代表一条后缀表达式。表达式中只含有+、-、*、/四种运算符和26个小写英文字母，不含其它字符。每一个英文字母代表一个正整数：
a = 1,b = 2,c = 3...y = 25,z = 26。

Output
每一个输入样例，单独一行输出结果：后缀表达式的值，一个正实数S，保留两位小数。


Sample Input
Copy sample input to clipboard
2
ab+c*
int**py++
Sample Output
9.00
2561.00
*/

#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    string pos;
    cin >> pos;
    stack<float> digit;
    stack<char> alpha;
    for (size_t i = 0; i < pos.size(); i++) {
      if (isalpha(pos[i])) {
        digit.push(pos[i] - 'a' + 1);
      } else {
        float b = digit.top();
        digit.pop();
        float a = digit.top();
        digit.pop();

        if (pos[i] == '+') {
          digit.push(a+b);
        } else if (pos[i] == '-') {
          digit.push(a-b);
        } else if (pos[i] == '*') {
          digit.push(a * b);
        } else if (pos[i] == '/') {
          digit.push(a / b);
        }

      }
    }
    printf("%.2f\n", digit.top());
  }
  return 0;
}
