//
// Created by jun on 2020/5/10.
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

/*
    1、要求唯一，使用map记录给个点出现的次数，不唯一就不考虑了；
    2、使用滑动窗口逐个判断每个点是否满足要求: 色差超过TOL才考虑 => 不超过色差: |A-B| <= TOL <==> -TOL <= A - B <= TOL
*/
int n, m, tol;
vector<vector<int>> v;

bool judge(int i, int j) {
    int dir[8][2] = {{-1, -1},
                     {-1, 0},
                     {-1, 1},
                     {0,  1},
                     {1,  1},
                     {1,  0},
                     {1,  -1},
                     {0,  -1}};
    for (auto &k : dir) {
        int tx = i + k[0];
        int ty = j + k[1];
        if (tx >= 0 && tx < n && ty >= 0 && ty < m
            && v[i][j] - v[tx][ty] >= 0 - tol
            && v[i][j] - v[tx][ty] <= tol)
            return false;
    }
    return true;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1068.txt", "r", stdin);
#endif
    scanf("%d%d%d", &m, &n, &tol);
    int cnt = 0, x = 0, y = 0;
    v.resize(n, vector<int>(m));
    map<int, int> times;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &v[i][j]);
            times[v[i][j]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (times[v[i][j]] > 1) continue;
            if (judge(i, j)) {
                cnt++;
                x = i + 1;
                y = j + 1;
            }
        }
    }
    if (cnt == 1) printf("(%d, %d): %d", y, x, v[x - 1][y - 1]);
    else if (cnt == 0) printf("Not Exist");
    else printf("Not Unique");
    return 0;
}

