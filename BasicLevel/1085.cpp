//
// Created by jun on 2020/6/6.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct school {
    string name;
    int totalWightScore, studentNum;
};

bool cmp(school a, school b) {
    if (a.totalWightScore != b.totalWightScore)
        return a.totalWightScore > b.totalWightScore;
    else if (a.studentNum != b.studentNum)
        return a.studentNum < b.studentNum;
    else
        return a.name < b.name;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1085.txt", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    unordered_map<string, int> schoolCountMap;
    unordered_map<string, double> schoolScoreSumMap;
    for (int i = 0; i < n; i++) {
        string id, schoolName;
        cin >> id;
        double score;
        scanf("%lf", &score);
        cin >> schoolName;
        for (char &j : schoolName)
            j = (char) tolower(j);
        if (id[0] == 'B')
            score /= 1.5;
        else if (id[0] == 'T')
            score *= 1.5;
        schoolScoreSumMap[schoolName] += score;
        schoolCountMap[schoolName]++;
    }
    vector<school> ans;
    for (auto it = schoolCountMap.begin(); it != schoolCountMap.end(); it++)
        ans.push_back(school{
                it->first,  // name
                (int) schoolScoreSumMap[it->first],  // totalWightScore
                schoolCountMap[it->first] // studentNum
        });
    sort(ans.begin(), ans.end(), cmp);
    int rank = 0, pre = -1;
    printf("%lu\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        if (pre != ans[i].totalWightScore) rank = i + 1;
        pre = ans[i].totalWightScore;
        printf("%d ", rank);
        cout << ans[i].name;
        printf(" %d %d\n", ans[i].totalWightScore, ans[i].studentNum);
    }
    return 0;
}

