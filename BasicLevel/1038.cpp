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
    使用自定义哈希表
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1038.txt", "r", stdin);
#endif
    int n, m, temp;
    scanf("%d", &n);
    vector<int> scores(101);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        scores[temp]++;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &temp);
        if (i) printf(" ");
        printf("%d", scores[temp]);
    }
    return 0;
}

