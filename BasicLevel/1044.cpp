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
    1、0~12 -> a
    2、13~24 -> b
    3、n -> str:
        3.1 n / 13 -> b[n/13];
        3.2 (n /13) && (n %13) -> " "
        3.3 (n %13) && n == 0 -> a[n %13]
    4、str -> n:
        4.1 s.substr(0, 3) 基本位
        4.2 if (len(s) > 4) -> s.substr(4, 3) 进位
        4.3 s1 in b, s2 in a -> b.index(s1) * 13 + a.index(s2)
*/
string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"####", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string s;
int len;

void func1(int n) {
    if (n / 13) cout << b[n / 13];
    if ((n / 13) && (n % 13)) cout << " ";
    if (n % 13 || n == 0) cout << a[n % 13];
}

void func2() {
    int t1 = 0, t2 = 0;
    string s1 = s.substr(0, 3), s2; /* s1: 0开始，取3个 */
    if (len > 4) s2 = s.substr(4, 3); /* s2: 4开始，取3个 */
    for (int j = 1; j <= 12; j++) {
        if (s1 == a[j] || s2 == a[j]) t2 = j;
        if (s1 == b[j]) t1 = j;
    }
    cout << t1 * 13 + t2;
}


int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1044.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        len = s.length();
        if (s[0] >= '0' && s[0] <= '9')
            func1(stoi(s));
        else
            func2();
        cout << endl;
    }
    return 0;
}
