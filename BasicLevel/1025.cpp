//
// Created by jun on 2020/4/15.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    输入样例:
    00100 6    4 -> head n k
    00000 4    99999
    00100 1    12309
    68237 6    -1
    33218 3    00000
    99999 5    68237
    12309 2    33218
    temp data next

    输入样例正确的连接顺序：
    00100   1     12309
    12309   2     33218
    33218   3     00000
    00000   4     99999
    99999   5     68237
    68237   6     -1
    list
Steps:
    1、读入第一行数据 -> head n k
    2、以下读入每行数据 -> temp data[temp] next[temp]
    3、按地址导出正确连接顺序，存储地址到list；(可能有无效结点，用计数器统计有效结点个数)
    4、子列翻转
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1025.txt", "r", stdin);
#endif
    int head, k, n, temp;
    cin >> head >> n >> k;
    int data[100005], next[100005], list[100005];
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cin >> data[temp] >> next[temp];
    }
    int cnt = 0;
    while (head != -1) {
        list[cnt++] = head;
        head = next[head];
    }
    for (int i = 0; i < (cnt - cnt % k); i += k)
        reverse(begin(list) + i, begin(list) + i + k);
    for (int i = 0; i < cnt - 1; i++)
        printf("%05d %d %05d\n", list[i], data[list[i]], list[i + 1]);
    printf("%05d %d -1\n", list[cnt - 1], data[list[cnt - 1]]);

    return 0;
}

