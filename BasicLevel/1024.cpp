//
// Created by jun on 2020/4/26.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

/*
    1、提取基数 -> t，幂 -> n
    2、若是负数，输出`-`
    3、对于负幂: 基数前添 n - 1个0
    对于正幂: key point: 基数后添n-1个0


*/
using namespace std;

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1024.txt", "r", stdin);
#endif
    string s;
    cin >> s;
    int i = 0;
    while (s[i] != 'E') i++;
    string t = s.substr(1, i - 1);   /* 基数 */
    int n = stoi(s.substr(i + 1));  /* 幂 */
    if (s[0] == '-') cout << '-';
    if (n < 0) {  /* 负幂 */
        cout << "0.";
        for (int j = 0; j < abs(n) - 1; j++) cout << '0';  /* 先添n-1个0 */
        for (char c: t)  /* 输出基数，不含`.` */
            if (c != '.') cout << c;
    } else {  /* 正幂 */
        cout << t[0];
        int cnt, j;  /* t[1] = '.' 忽略 */
        for (j = 2, cnt = 0; j < t.length() && cnt < n; j++, cnt++) cout << t[j];
        if (j == t.length()) {  /* 由于j == t.length()退出循环 */
            for (int k = 0; k < n - cnt; k++) cout << '0';
        } else {  /* 由于 cnt == n 退出循环 */
            cout << '.';
            for (int k = j; k < t.length(); k++) cout << t[k];
        }
    }
    return 0;
}

