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

/*
    遍历应该输入的字符串
    1、转大写，在坏键中查找，找到则跳过, 不然下一步;
    2、判断是否为大写，若是且坏键中存在'+'，跳过，否则输出；
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1033.txt", "r", stdin);
#endif
    string bad, should;
    getline(cin, bad);  /* 可能出现`空格`或Tab */
    getline(cin, should);
    for (char c: should) {
        if (bad.find(toupper(c)) != string::npos) continue;
        if (isupper(c) && bad.find('+') != string::npos) continue;
        cout << c;
    }
    return 0;
}

