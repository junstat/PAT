//
// Created by jun on 2020/5/16.
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
    freopen("input/1072.txt", "r", stdin);
#endif
    int n, m, temp, k, ban[10001] = {0}, caughtStu = 0, caughtThing = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &temp);
        ban[temp] = 1;
    }
    for (int i = 0; i < n; i++) {
        char name[10];
        bool flag = false;
        scanf("%s %d", name, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &temp);
            if (ban[temp]) {
                if (!flag) {
                    printf("%s:", name);
                    flag = true;
                }
                printf(" %04d", temp);
                caughtThing++;
            }
        } /* end j loop */
        if (flag) {
            printf("\n");
            caughtStu++;
        }
    } /* end i loop */
    printf("%d %d\n", caughtStu, caughtThing);
    return 0;
}
