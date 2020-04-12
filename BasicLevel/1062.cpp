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

using namespace std;

/*
  分析: 设读入数据为 n_1 m_1 n_2 m_2 k
  1. 若n_1/m_1 > n_2/m_2,即n_1 * m_2 > m_1 * n_2, 则交换区间端点；
  2. 设要求的分数为num/k，k已给出，下面求num
       2.1 由n_1/m_1 < num/k 即 n1 * k < m1 * num, 找出第一个满足条件的num即为起点
       2.2 在所求区间内，num 与k互素即可
 */

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1062.txt", "r", stdin);
#endif
    int n1, m1, n2, m2, k, num;
    bool notFirstPrint = false;
    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
    if (n1 * m1 > m1 * n2) {
        swap(n1, n2);
        swap(m1, m2);
    }
    for (num = 1; num <= k; num++) {
        if (n1 * k >= m1 * num || num * m2 >= k * n2)
            continue;
        if (gcd(num, k) == 1) {
            printf("%s%d/%d", notFirstPrint ? " " : "", num, k);
            notFirstPrint = true;
        }
    }
    return 0;
}

