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

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1021.txt", "r", stdin);
#endif
    int res[10] = {0};
    string s;
    cin >> s;
    for (char c: s)
        res[c - '0']++;
    for (int i = 0; i < 10; i++)
        if (res[i])
            printf("%d:%d\n", i, res[i]);
    return 0;
}

