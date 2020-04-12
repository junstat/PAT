//
// Created by jun on 2020/5/2.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    1. 注意 p <= 10e9;
    2. 用vector v保存读入的数列，排序;
    3. 遍历判断v[i]是否满足要求;
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1030.txt", "r", stdin);
#endif
    int n;
    long long p;
    scanf("%d%lld", &n, &p);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + result; j < n; j++) {
            if (v[j] > v[i] * p)
                break;
            result = max(result, j - i + 1);
        }
    }
    cout << result;
    return 0;
}

