//
// Created by jun on 2020/7/18.
//

#include <iostream>
#include <string>
using namespace std;


/*
   1. 输入 -> 姓名，学号，成绩 -> string name, string studentId,int  score
   2. maxScore = -1; minScore = 101;
   3. 遍历即可 -> maxName, minName, maxStudentId, minStudentId;
 */

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1004.txt", "r", stdin);
#endif
    int n, score, maxScore = -1, minScore = 101;
    string name, studentId, maxName, minName, maxStudentId, minStudentId;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> studentId >> score;
        if (score > maxScore) {
            maxScore = score;
            maxName = name;
            maxStudentId = studentId;
        }
        if (score < minScore) {
            minScore = score;
            minName = name;
            minStudentId = studentId;
        }
    }
    cout << maxName << " " << maxStudentId << "\n"
         << minName << " " << minStudentId;
    return 0;
}

