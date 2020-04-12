//
// Created by jun on 2020/5/11.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1069.txt", "r", stdin);
#endif
    int m, n, s;
    scanf("%d%d%d", &m, &n, &s);
    string str;
    map<string, int> mapp;  // 统计中奖次数
    bool flag = false;      // 标记是否已经有人中奖
    for (int i = 1; i <= m; i++) {
        cin >> str;
        if (mapp[str] == 1) s += 1;  // 当前用户已中奖，跳过，顺次取下一位
        if (i == s && mapp[str] == 0) {
            mapp[str] = 1;
            cout << str << endl;
            flag = true;
            s += n;
        }
    }
    if (!flag) cout << "Keep going...";
    return 0;
}

