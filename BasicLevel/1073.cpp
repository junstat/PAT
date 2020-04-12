//
// Created by jun on 2020/5/16.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

/*
    分析: 错误是指错选或漏选。用异或运算来判断一个选项和正确选项是否匹配，如果是匹配的，那么异或的结果应当是0；如果不匹配，那么这个选项就是存在错误或者漏选
    的情况~通过异或操作的结果，再用与运算就可以把错选和漏选的选型找出来~fullScore表示一道题满分的分值；trueOpt表示正确的选型，存储的是正确选型二进制的
    值，二进制由hash给出分别是1,2,4,8,16；cnt是错误次数，maxCnt是最大错误次数~
*/
using namespace std;

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1073.txt", "r", stdin);
#endif
    int n, m, optNum, trueNum, temp, maxCnt = 0;
    int hash[] = {1, 2, 4, 8, 16}, opt[1010][110] = {0};
    char c;
    scanf("%d %d", &n, &m);
    vector<int> fullScore(m), trueOpt(m);
    vector<vector<int>> cnt(m, vector<int>(5));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &fullScore[i], &optNum, &trueNum);
        for (int j = 0; j < trueNum; j++) {
            scanf(" %c", &c);
            trueOpt[i] += hash[c - 'a'];  // 统计正确选型
        }
    }
    for (int i = 0; i < n; i++) {
        double grade = 0;
        for (int j = 0; j < m; j++) {
            getchar();
            scanf("(%d", &temp);
            for (int k = 0; k < temp; k++) {
                scanf(" %c)", &c);
                opt[i][j] += hash[c - 'a'];  // 统计输入选型
            }
            int el = opt[i][j] ^trueOpt[j];
            if (el) {
                if ((opt[i][j] | trueOpt[j]) == trueOpt[j]) {
                    grade += fullScore[j] * 1.0 / 2;
                }
                if (el) {
                    for (int k = 0; k < 5; k++)
                        if (el & hash[k]) cnt[j][k]++;
                }
            } else {
                grade += fullScore[j];
            }
        }
        printf("%.1f\n", grade);
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 5; j++)
            maxCnt = maxCnt > cnt[i][j] ? maxCnt : cnt[i][j];
    if (maxCnt == 0) {
        printf("Too simple\n");
    } else {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < cnt[i].size(); j++) {
                if (maxCnt == cnt[i][j])
                    printf("%d %d-%c\n", maxCnt, i + 1, 'a' + j);
            }
    }
    return 0;
}

