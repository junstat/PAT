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

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1066.txt", "r", stdin);
#endif
    int m, n, a, b, rep, temp;
    scanf("%d %d %d %d %d", &m, &n, &a, &b, &rep);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &temp);
            if (temp >= a && temp <= b)
                temp = rep;
            if (j != 0) printf(" ");
            printf("%03d", temp);
        }
        printf("\n");
    }
    return 0;
}

