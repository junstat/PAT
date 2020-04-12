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
int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2}; // 权重
int M[11] = {1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2}; // M值

bool isTrue(string s) {
    int sum = 0;
    for (int i = 0; i < 17; i++) {
        if (s[i] < '0' || s[i] > '9') return false;
        sum += (s[i] - '0') * weight[i];
    }
    int temp = (s[17] == 'X') ? 10 : (s[17] - '0');  // 校验码
    return M[sum % 11] == temp;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1031.txt", "r", stdin);
#endif
    int n, flag = 0;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (!isTrue(s)) {
            cout << s << endl;
            flag = 1;
        }
    }
    if (!flag) cout << "All passed";
    return 0;
}

