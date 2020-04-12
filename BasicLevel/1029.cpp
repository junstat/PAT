//
// Created by jun on 2020/5/2.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    遍历应输入的文字，对于遍历字符，若不在实际输入文字中也不在结果字符串(注意结果字符串中均为大写字符)中，则添加该字符到结果字符串。
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1029.txt", "r", stdin);
#endif
    string s1, s2, res;
    cin >> s1 >> s2;
    for (char c: s1) {
        if (s2.find(c) == string::npos && res.find(toupper(c)) == string::npos)
            res += toupper(c);
    }
    cout << res;
    return 0;
}

