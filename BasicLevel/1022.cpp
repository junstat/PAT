//
// Created by jun on 2020/4/26.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
    计算A+B=res后，res % D -> s[100]，用i统计有效位
    i - 1 -> j, 逐位输出
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1022.txt", "r", stdin);
#endif
    int A, B, D;
    scanf("%d%d%d", &A, &B, &D);
    int res = A + B;
    if (!res) {
        printf("0");
        return 0;
    }
    int i = 0, s[100];
    while (res) {
        s[i++] = res % D;
        res /= D;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d", s[j]);
    return 0;
}

