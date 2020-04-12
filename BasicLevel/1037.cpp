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
    1、通过交换，确保大值在后，发生交换需输出负号；
    2、对于借位的处理，t < c ? t - c + 29 : t - c;
*/
int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1037.txt", "r", stdin);
#endif
    int a, b, c, m, n, t, x, y, z;
    scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &m, &n, &t);
    if (a > m || (a == m && b > n) || (a == m && b == n && c > t)) {
        swap(a, m);
        swap(b, n);
        swap(c, t);
        printf("-");
    }
    z = t < c ? t - c + 29 : t - c;
    n = t < c ? n - 1 : n;
    y = n < b ? n - b + 17 : n - b;
    x = n < b ? m - a - 1 : m - a;
    printf("%d.%d.%d", x, y, z);
    return 0;
}

