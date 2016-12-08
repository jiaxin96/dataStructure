#include <iostream>
#include <cstdio>
using namespace std;
int binSearch(const int s[], const int size, const int target)
{
// 请将实现代码添加在这里
    if(size == 0) {
        printf("$$$$");
        return -1;
    }
    int pre=0;
    int pos=size-1;
    int mid=(size-1)/2;
    while(pre < pos) {
            if (s[mid] == target) {
                while(mid < size-1 && s[mid+1] == target) {
                    mid++;
                }
                return mid;
            } else if (s[mid] < target) {
                pre = mid + 1;
                mid = (pos + pre)/2;
            } else {
                pos = mid - 1;
                mid = (pos + pre)/2;
            }
    }
    if (pre == pos) {
        if (s[pre] == target) return pre;
    }

    return -1;
}


int main() {
int s[9] = {0,0,1,1,2,2,3,3,4};

cout << binSearch(s,9,0) << endl;  //输出5

cout << binSearch(s,9,4) << endl;  //输出-1

return 0;
}
