//
// Created by jun on 2020/7/12.
//

#include <iostream>

using namespace std;

/*
   给定输入 n
    n /= 2;             if n % 2 == 0
    n = (3*n + 1) /2;   else
 */

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1001.txt", "r", stdin);
#endif
    int n, step = 0;
    scanf("%d", &n);
    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = (3 * n + 1) / 2;
        step++;
    }
    printf("%d", step);
    return 0;
}
