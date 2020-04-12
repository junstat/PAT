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

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1056.txt", "r", stdin);
#endif
    int n, temp, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        res += 11 * temp;
    }
    printf("%d", res * (n - 1));
    return 0;
}

