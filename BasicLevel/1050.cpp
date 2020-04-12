//
// Created by jun on 2020/5/5.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
    1、关于m, n的取值, n: sqrt(N)...1, m = N / n;
    2、外循环level: 有几层。 m偶: m / 2, m奇: m/2+1 ==> m / 2 + m % 2
    3、内循环:
        →: row: i,            col: [i, n-1-i];
        ↓: row: [i+1, m-2-i], col: n - 1 -i;
        ←: row: m-1-i,        col: [n-1-i, i];
        ↑: row: [m-2-i,i+1],  col: i;
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1050.txt", "r", stdin);
#endif
    int N, m, n;
    scanf("%d", &N);
    int insertedIndex = N - 1;
    for (n = sqrt((double) N); n >= 1; n--)
        if (N % n == 0) {
            m = N / n;
            break;
        }
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &nums[i]);
    sort(nums.begin(), nums.end());
    vector<vector<int>> res(m, vector<int>(n));
    int level = m / 2 + m % 2;
    for (int i = 0; i < level; i++) {
        for (int j = i; j <= n - 1 - i && insertedIndex >= 0; j++)
            res[i][j] = nums[insertedIndex--];
        for (int j = i + 1; j <= m - 2 - i && insertedIndex >= 0; j++)
            res[j][n - 1 - i] = nums[insertedIndex--];
        for (int j = n - i - 1; j >= i && insertedIndex >= 0; j--)
            res[m - 1 - i][j] = nums[insertedIndex--];
        for (int j = m - 2 - i; j >= i + 1 && insertedIndex >= 0; j--)
            res[j][i] = nums[insertedIndex--];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", res[i][j]);
            if (j != n - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}

