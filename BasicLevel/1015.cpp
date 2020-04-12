//
// Created by jun on 2020/7/20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
    1. struct student 存储数据: id, morality, ability
    2. 分类:
        2.0 未录取:  morality < L || ability < L
        2.1 才德全尽: morality >= H && ability >= H
        2.2 德胜才:  morality >= H && H > ability >= L
        2.3 才德兼亡, 德胜才: H > morality && H > ability && morality >= ability >= L
        2.4 else 过线
 */

struct student {
    int id;
    int morality;
    int ability;
};

bool cmp(student a, student b) {
    if ((a.morality + a.ability) != (b.morality + b.ability))
        return (a.morality + a.ability) > (b.morality + b.ability);
    else if (a.morality != b.morality)
        return a.morality > b.morality;
    else
        return a.id < b.id;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1015.txt", "r", stdin);
#endif
    int N, M, L, H;
    cin >> N >> L >> H;
    M = N;
    vector<student> students[4];
    student input;
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &input.id, &input.morality, &input.ability);
        if (input.morality < L || input.ability < L)
            M--;
        else if (input.morality >= H && input.ability >= H)
            students[0].push_back(input);
        else if (input.morality >= H && input.ability < H)
            students[1].push_back(input);
        else if (input.morality < H && input.ability < H && input.morality >= input.ability)
            students[2].push_back(input);
        else
            students[3].push_back(input);
    }
    printf("%d\n", M);
    for (auto & group : students) {
        sort(group.begin(), group.end(), cmp);
        for (auto stu: group)
            printf("%d %d %d\n", stu.id, stu.morality, stu.ability);
    }
    return 0;
}
