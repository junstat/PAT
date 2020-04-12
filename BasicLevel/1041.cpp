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
    使用一个二维数组保存 准考证号, 座位号； 试机号为index
*/
int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1041.txt", "r", stdin);
#endif
    string stu[1005][2], s1, s2;
    int n, m, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> t >> s2;
        stu[t][0] = s1;
        stu[t][1] = s2;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        cout << stu[t][0] << " " << stu[t][1] << endl;
    }

    return 0;
}

