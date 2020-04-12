//
// Created by jun on 2020/5/22.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
    1. input value -> res n
    2. 已经给出了初始值，循环计算next即可
    3. 计算next的方法: 标记起始下标start，终止下标end，end-start即为len
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1084.txt", "r", stdin);
#endif
    string res;  // final result
    int n, end;
    cin >> res >> n;
    for (int cnt = 1; cnt < n; cnt++) {
        string next;  // next value
        for (int start = 0; start < res.length(); start = end) {  // start: start index of not repeated num
            for (end = start; end < res.length() && res[end] == res[start]; end++);
            next += res[start] + to_string(end - start);
        }
        res = next;
    }
    cout << res;
    return 0;
}

