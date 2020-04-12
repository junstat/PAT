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
#include <set>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1065.txt", "r", stdin);
#endif
    int n, a, b, m;
    scanf("%d", &n);
    vector<int> couple(100000, -1);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        couple[a] = b;
        couple[b] = a;
    }
    scanf("%d", &m);
    vector<int> guest(m), isExist(100000);
    for (int i = 0; i < m; i++) {
        scanf("%d", &guest[i]);
        if (couple[guest[i]] != -1) isExist[couple[guest[i]]] = 1;
    }
    set<int> res;
    for (int i = 0; i < m; i++) {
        if (!isExist[guest[i]]) res.insert(guest[i]);
    }
    printf("%lu\n", res.size());
    for (auto it = res.begin(); it != res.end(); it++) {
        if (it != res.begin()) printf(" ");
        printf("%05d", *it);
    }
    return 0;
}

