/**
 * File: e:\code\code\dataStructure\SelfTest\String\全排列\递归实现可以去重.cc
 * Project: e:\code\code\dataStructure
 * Created Date: Thursday, July 27th 2017, 1:38:10 pm
 * Author: JX
 * -----
 * Last Modified: Thu Jul 27 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

// 方法二
// i 和 j交换的条件是[i,j)间没有字符和第j个相等,相等意味着已经可以被别的节点生成
// bool test(string &str, int b, int e) {
//     for (size_t i = b; i < e; i++)
//     {
//         if (str[i] == str[e]) return false;
//     }
//     return true;
// }

// void getPermutation(string& str, int start) {
//     if (start == str.length()-1) {
//         cout << str << endl;
//         return;
//     }
//     for (size_t i = start; i < str.length(); i++)
//     {
        
//         if (test(str, start, i)) {
//             swap(str, start, i);
//             getPermutation(str, start+1);
//             swap(str, start, i);        
//         }
        
//     }
// }

#include <iostream>
#include <string>
using namespace std;

void swap(string & str, int i, int j) {
    char t = str[i];
    str[i] = str[j];
    str[j] = t;
}

void getPermutation(string& str, int start) {
    if (start == str.length()-1) {
        cout << str << endl;
        return;
    }
    for (size_t i = start; i < str.length(); i++)
    {
        
        while(i < str.length()-1 && str[i+1] == str[i]) ++i; // 方法一
        
        swap(str, start, i);
        getPermutation(str, start+1);
        swap(str, start, i);        
    }
}

int main() {
    string str;
    cin >> str;
    getPermutation(str, 0);
    return 0;
}