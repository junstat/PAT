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
#include <set>

using namespace std;

/*
    各个数位上的数求和,放入set即可
*/

int getFriendNum(int num) {
    int sum = 0;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1064.txt", "r", stdin);
#endif
    set<int> res;
    int n, num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        res.insert(getFriendNum(num));
    }
    printf("%lu\n", res.size());
    for (auto it = res.begin(); it != res.end(); it++) {
        if (it != res.begin()) printf(" ");
        printf("%d", *it);
    }
    return 0;
}

