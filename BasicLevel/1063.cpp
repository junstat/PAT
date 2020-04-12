//
// Created by jun on 2020/5/10.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1063.txt", "r", stdin);
#endif
    int n, a, b;
    double res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        res = max(res, sqrt(a * a + b * b));
    }
    printf("%.2f", res);
    return 0;
}
