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

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1061.txt", "r", stdin);
#endif
    int n, m, temp;
    scanf("%d%d", &n, &m);
    vector<int> score(m), ans(m);
    for (int i = 0; i < m; i++)
        scanf("%d", &score[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &ans[i]);
    for (int i = 0; i < n; i++) {
        int total = 0;
        for (int j = 0; j < m; j++) {
            scanf("%d", &temp);
            if (temp == ans[j])
                total += score[j];
        }
        printf("%d\n", total);
    }
    return 0;
}

