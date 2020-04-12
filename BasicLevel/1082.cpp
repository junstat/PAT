//
// Created by jun on 2020/5/19.
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
    freopen("input/1082.txt", "r", stdin);
#endif
    int n, x, y, maxDistance = -1, minDistance = 99999;
    scanf("%d", &n);
    string name, maxName, minName;
    for (int i = 0; i < n; i++) {
        cin >> name >> x >> y;
        int dis = x * x + y * y;
        if (dis > maxDistance) {
            maxName = name;
            maxDistance = dis;
        }
        if (dis < minDistance) {
            minName = name;
            minDistance = dis;
        }
    }
    cout << minName << " " << maxName;
    return 0;
}

