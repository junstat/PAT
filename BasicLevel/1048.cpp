//
// Created by jun on 2020/5/5.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
    a,b长度对齐: reverse, append '0'
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1048.txt", "r", stdin);
#endif
    string a, b, c;
    cin >> a >> b;
    int lenA = a.length(), lenB = b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (lenA > lenB)
        b.append(lenA - lenB, '0');
    else
        a.append(lenB - lenA, '0');
    char str[14] = {"0123456789JQK"};
    for (int i = 0; i < a.length(); i++) {
        if (i % 2 == 0) {
            c += str[(a[i] - '0' + b[i] - '0') % 13];
        } else {
            int temp = b[i] - a[i];
            c += str[temp < 0 ? temp + 10 : temp];
        }
    }
    for (int i = c.length() - 1; i >= 0; i--)
            cout << c[i];
    return 0;
}

