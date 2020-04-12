//
// Created by jun on 2020/5/11.
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
    freopen("input/1071.txt", "r", stdin);
#endif
    int total, k, n1, b, t, n2;
    scanf("%d%d", &total, &k);
    for (int i = 0; i < k; i++) {
        cin >> n1 >> b >> t >> n2;
        int ans = n1 > n2 ? 0 : 1;
        if (total == 0) {
            printf("Game Over.\n");
            return 0;
        } else if (t > total) {
            printf("Not enough tokens.  Total = %d.\n", total);
        } else if (ans == b) {
            total += t;
            printf("Win %d!  Total = %d.\n", t, total);
        } else if (ans != b) {
            total -= t;
            printf("Lose %d.  Total = %d.\n", t, total);
        }
    }
    return 0;
}

