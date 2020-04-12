//
// Created by jun on 2020/4/26.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
    1、自定义结构体保存月饼数据: mount(库存), prince(售价), unit(单价)；
    2、自定义按单价排序；
*/

struct moonCake {
    float mount, price, unit;
};

bool cmp(moonCake a, moonCake b) {
    return a.unit > b.unit;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1020.txt", "r", stdin);
#endif
    int N, D;
    cin >> N >> D;
    vector<moonCake> v(N);
    for (int i = 0; i < N; i++) scanf("%f", &v[i].mount);
    for (int i = 0; i < N; i++) {
        scanf("%f", &v[i].price);
        v[i].unit = v[i].price / v[i].mount;
    }
    sort(v.begin(), v.end(), cmp);
    float result = 0;
    for (int i = 0; i < N; i++) {
        if (v[i].mount <= D) {
            result += v[i].price;
        } else {
            result += v[i].unit * D;
            break;
        }
        D -= v[i].mount;
    }
    printf("%.2f", result);
    return 0;
}

