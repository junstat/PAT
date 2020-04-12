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

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1046.txt", "r", stdin);
#endif
    int N, jiaHan, jiaHua, yiHan, yiHua, jiaHe = 0, yiHe = 0, sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> jiaHan >> jiaHua >> yiHan >> yiHua;
        sum = jiaHan + yiHan;
        if (sum == jiaHua && sum != yiHua)
            yiHe++;
        if (sum != jiaHua && sum == yiHua)
            jiaHe++;
    }
    cout << jiaHe << " " << yiHe;
    return 0;
}

