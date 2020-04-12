//
// Created by jun on 2020/5/17.
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
    freopen("input/1077.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int g2, g1 = 0, cnt = -2, temp, maxN = -1, minN = m + 1;
        cin >> g2;
        for (int j = 0; j < n - 1; j++) {
            cin >> temp;
            if (temp >= 0 && temp <= m) {
                if (temp > maxN) maxN = temp;
                if (temp < minN) minN = temp;
                g1 += temp;
                cnt++;
            }
        }
        cout << int((((g1 - minN - maxN) * 1.0 / cnt) + g2) / 2 + 0.5) << endl;
    }

    return 0;
}
