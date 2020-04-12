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

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1039.txt", "r", stdin);
#endif
    int pearls[256] = {0};  /* 记录摊主的不同珠子个数 */
    string a, b;
    cin >> a >> b;
    for (char i : a)
        pearls[i]++;
    int result = 0;
    for (char i: b) {
        if (pearls[i])
            pearls[i]--;
        else
            result++;
    }
    if (result)
        printf("No %d", result);
    else
        printf("Yes %lu", a.length() - b.length());
    return 0;
}

