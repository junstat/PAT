//
// Created by jun on 2020/5/6.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
    1、关于表情的处理，循环读取3行字符串，遍历, 逐个截取(substr)表情. -> vector<vector<string>> emoji;
    2、关于异常下标的处理，1 < index < n；
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1052.txt", "r", stdin);
#endif
    vector<vector<string>> emoji;
    for (int i = 0; i < 3; i++) {
        string s;
        getline(cin, s);
        vector<string> row;
        int start = 0, end = 0;
        while (start < s.length()) {
            if (s[start++] != '[') continue;
            while (end++ < s.length()) {
                if (s[end] == ']') {
                    row.push_back(s.substr(start, end - start));
                    break;
                } /* end of `end` condition */
            } /* end of `end` while */
        } /* end of `start` while */
        emoji.push_back(row);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int leftHand, leftEye, mouth, rightHand, rightEye;
        cin >> leftHand >> leftEye >> mouth >> rightEye >> rightHand;
        if (leftHand > emoji[0].size() || leftEye > emoji[1].size() || mouth > emoji[2].size() ||
            rightHand > emoji[0].size() || rightEye > emoji[1].size() || leftHand < 1 || leftEye < 1 ||
            mouth < 1 || rightHand < 1 || rightEye < 1) {
            cout << "Are you kidding me? @\\/@" << endl;
            continue;
        }
        cout << emoji[0][leftHand - 1] << "(" << emoji[1][leftEye - 1] << emoji[2][mouth - 1] << emoji[1][rightEye - 1]
             << ")" << emoji[0][rightHand - 1] << endl;
    }
    return 0;
}

