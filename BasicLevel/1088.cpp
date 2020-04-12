//
// Created by jun on 2020/4/20.
//
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/*
    m: mine 自己的能力值
    jia: 甲的能力值，2位数
    yi: reverse(jia)
    bing:
          |jia - yi| = x * bing ==> bing = |jia - yi| / x
          yi = y * bing
*/

void print(int mine, double other) {
    if (mine == other) printf(" Ping");
    else if (mine < other) printf(" Cong");
    else printf(" Gai");
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1088.txt", "r", stdin);
#endif
    int m, x, y;
    scanf("%d%d%d", &m, &x, &y);
    int jia, yi;
    double bing;
    for (jia = 99; jia >= 10; jia--) {
        yi = jia % 10 * 10 + jia / 10;
        bing = abs(jia - yi) * 1.0 / x;
        if (yi == y * bing) {
            cout << jia;
            print(m, jia);
            print(m, yi);
            print(m, bing);
            return 0;
        }
    }
    cout << "No Solution";
    return 0;
}

