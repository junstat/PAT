//
// Created by jun on 2020/5/8.
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
    1、排名保存到数组里, ID做index，排名做value；
    2、检索ID，保存到set里。
*/

bool isPrime(int a) {
    if (a <= 1) return false;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0)
            return false;
    }
    return true;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1059.txt", "r", stdin);
#endif
    int n, k;
    int ran[10000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int id;
        scanf("%d", &id);
        ran[id] = i + 1;
    }
    scanf("%d", &k);
    set<int> ss;
    for (int i = 0; i < k; i++) {
        int id;
        scanf("%d", &id);
        printf("%04d: ", id);
        if (ran[id] == 0) {
            printf("Are you kidding?\n");
            continue;
        }
        if (ss.find(id) == ss.end()) {
            ss.insert(id);
        } else {
            printf("Checked\n");
            continue;
        }
        if (ran[id] == 1) {
            printf("Mystery Award\n");
        } else if (isPrime(ran[id])) {
            printf("Minion\n");
        } else {
            printf("Chocolate\n");
        }
    }
    return 0;
}

