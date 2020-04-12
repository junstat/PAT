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
    主元: 非逆序对
    排序后，左侧最大值 < 主元
    对原序列sort排序，逐个比较，当当前元素没有变化并且它左边的所有值的最大值都比它小的时候就可以认为它一定是主元（很容易证明正确性的，毕竟无论如何当前这个数要满足左边都比他小右边都比他大，那它的排名【当前数在序列中处在第几个】一定不会变）～
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1045.txt", "r", stdin);
#endif
    int n, maxLeft = 0, cnt = 0;
    int res[100000];
    scanf("%d", &n);
    vector<int> origin(n), ordered(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &origin[i]);
        ordered[i] = origin[i];
    }
    sort(ordered.begin(), ordered.end());
    for (int i = 0; i < n; i++) {
        if (origin[i] == ordered[i] && origin[i] > maxLeft)
            res[cnt++] = origin[i];
        if (origin[i] > maxLeft)
            maxLeft = origin[i];
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        if (i) printf(" ");
        printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}

