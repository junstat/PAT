//
// Created by jun on 2020/9/30.
//
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


/*
   DA方面:
        单个考生用 struct 保存，含两个属性: 考号，成绩;
        所有考生存入 vector
        满足条件的 考生 struct 存入 vector
    Algorithm方面:
        Step1: 遍历读入所有考生
        Step2: 遍历读入统计要求，并做对应处理
            demandType = 1, 统计给定考试级别的考生，满足条件假如ans，之后排序即可
            demandType = 2, 统计给定考场号的 考生人数及总分
            demandType = 3, 统计给定日期下，各考场 及 考生人数， 输出: 考场号 人数。结构与考生信息重合，复用
        Step3: 排序，输出结果
        Step4: 结果空判断
 */

struct Examinee {
    string examId;
    int score;
};

bool cmp(const Examinee &a, const Examinee &b) {
    return a.score != b.score ? a.score > b.score : a.examId < b.examId;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("./input/1095.txt", "r", stdin);
#endif
    int n, m, demandType;
    string demandParameter;
    cin >> n >> m;
    vector<Examinee> examinees(n);
    for (int i = 0; i < n; i++)
        cin >> examinees[i].examId >> examinees[i].score;
    for (int i = 1; i <= m; i++) {
        cin >> demandType >> demandParameter;
        printf("Case %d: %d %s\n", i, demandType, demandParameter.c_str());
        vector<Examinee> ans;
        int cnt = 0, sum = 0;
        if (demandType == 1) {
            for (int j = 0; j < n; j++)
                if (examinees[j].examId[0] == demandParameter[0]) ans.push_back(examinees[j]);
        } else if (demandType == 2) {
            for (int j = 0; j < n; j++) {
                if (examinees[j].examId.substr(1, 3) == demandParameter) {
                    cnt++;
                    sum += examinees[j].score;
                }
            }
            if (cnt != 0) printf("%d %d\n", cnt, sum);
        } else if (demandType == 3) {
            unordered_map<string, int> examRoomPeopleNumbersMap;  // 统计： 考场， 人数
            for (int j = 0; j < n; j++)
                if (examinees[j].examId.substr(4, 6) == demandParameter)
                    examRoomPeopleNumbersMap[examinees[j].examId.substr(1, 3)]++;
            for (const auto &it: examRoomPeopleNumbersMap) ans.push_back({it.first, it.second});  // 把统计结果作为Examinee对象存入ans
        }
        sort(ans.begin(), ans.end(), cmp);
        for (auto &an : ans)
            printf("%s %d\n", an.examId.c_str(), an.score);
        if (
                ((demandType == 1 || demandType == 3) && ans.empty()) ||
                (demandType == 2 && cnt == 0)
                )
            printf("NA\n");
    }
    return 0;
}