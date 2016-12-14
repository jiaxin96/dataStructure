#include <iostream>

#include <string>

using namespace std;

void swap(char & a, char & b) {
    char t = a;
    a = b;
    b = t;
}

void AllRang(string & buf, int length, int num) {

    if (num == length - 1) {
        cout << buf << endl;
    } else {
        for (int i = num; i < length; ++i)
        {
            swap(buf[num], buf[i]);
            AllRang(buf, length, num + 1);
            swap(buf[num], buf[i]);
        }
    }
}

int main()
{
    string buf;
    cin >> buf;

    AllRang(buf, buf.length(), 0);

    return 0;
}