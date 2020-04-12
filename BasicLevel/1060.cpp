//
// Created by jun on 2020/5/8.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    1、从下标1开始存储n天的公里数，对n个数据从大到小排序;
    2、i表示了骑车的天数，那么满足a[i] > i的最大值即为所求~
*/

bool cmp(int a, int b) {
    return a > b;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1060.txt", "r", stdin);
#endif
    int a[1000000];
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, cmp);
    int ans = 0, p = 1;
    while (ans <= n && a[p] > p) {
        ans++;
        p++;
    }
    printf("%d", ans);
    return 0;
}

