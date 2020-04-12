//
// Created by jun on 2020/6/8.
//
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

/*
   DA方面:
        - 用map存储不相容映射关系， A物品可能存在多个不相容物品 B_1, B_2, ...
          =>  A: [B_1, B_2, ...]
        - 货物清单用vector存储
        - 货物是否出现用数组标识
    Algorithm:
        Step1: 读入不相容映射关系，存入map
        Step2: 读入货物清单inventory
        Step3: 遍历inventory，对于每个物品，取出对应不相容物品，判断该不相容物品是否已出现。
 */

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("./input/1090.txt", "r", stdin);
#endif
    int n, m, input1, input2;
    map<int, vector<int> > incompatibilityMap;  // 不相容映射关系
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &input1, &input2);
        incompatibilityMap[input1].push_back(input2);
        incompatibilityMap[input2].push_back(input1);
    }
    while (m--) {
        int cnt, found = 0, goods[100000] = {0};
        scanf("%d", &cnt);
        vector<int> inventory(cnt);
        for (int i = 0; i < cnt; i++) {
            scanf("%d", &inventory[i]);
            goods[inventory[i]] = 1;  // 标记物品inventory[i]已出现
        }
        for (int i: inventory)
            for (int j: incompatibilityMap[i])
                if (goods[j] == 1) found = 1;
        printf("%s\n", found ? "No" : "Yes");
    }
    return 0;
}
