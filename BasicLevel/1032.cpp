//
// Created by jun on 2020/5/4.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1032.txt", "r", stdin);
#endif
    int N;
    cin >> N;
    vector<int> records(N + 1);
    int num, score;
    for (int i = 0; i < N; i++) {
        cin >> num >> score;
        records[num] += score;
    }
    int maxScore = records[1], maxInd = 1;
    for (int i = 2; i <= N; i++) {
        if (maxScore < records[i]) {
            maxScore = records[i];
            maxInd = i;
        }
    }
    cout << maxInd << " " << maxScore;
    return 0;
}

