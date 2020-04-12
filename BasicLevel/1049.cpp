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
    分析: 设输入的第i个数为temp, 含temp片段的首、尾指针分别为p, q，
    p有i种选择(1, ..., i); q有(n - i + 1)种选择(i, ..., n).
    ==> 含temp片段有 i * (n-i+1)个
    ==> temp贡献和: temp * i * (n-i+1)
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1049.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    double temp, res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        res += temp * i * (n - i + 1);
    }
    printf("%.2lf", res);
    return 0;
}

