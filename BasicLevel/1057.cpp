//
// Created by jun on 2020/5/6.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    1、关于求和: 先转大写, 然后: c - 'A' + 1
    2、n % 2 == 0 -> cnt0++, 不然 cnt1++;
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1057.txt", "r", stdin);
#endif
    string s;
    getline(cin, s);
    int n = 0;
    for (char &c: s) {
        if (!isalpha(c)) continue;
        c = toupper(c);
        n += (c - 'A' + 1);
    }
    int cnt0 = 0, cnt1 = 0;
    while (n) {
        if (n % 2 == 0) {
            cnt0++;
        } else {
            cnt1++;
        }
        n /= 2;
    }
    printf("%d %d", cnt0, cnt1);
    return 0;
}

