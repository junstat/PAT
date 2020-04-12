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
    只需要保存最大成绩下标即可
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1047.txt", "r", stdin);
#endif
    int n, teamId, pId, score;
    cin >> n;
    int scores[1001] = {0}, maxTeamId = 1;
    for (int i = 0; i < n; i++) {
        scanf("%d-%d %d", &teamId, &pId, &score);
        scores[teamId] += score;
    }

    for (int i = 1; i < 1001; i++) {
        if (scores[i] > scores[maxTeamId]) {
            maxTeamId = i;
        }
    }
    printf("%d %d", maxTeamId, scores[maxTeamId]);
    return 0;
}

