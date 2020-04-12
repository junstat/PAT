//
// Created by jun on 2020/4/26.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    1、string 使用 sort 可实现排序, 自定义cmp 逆序;
    2、stoi: string -> int
    3、to_string: int -> string
*/

bool cmp(char a, char b) { return a > b; }

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1019.txt", "r", stdin);
#endif
    string source /* 源字符串 */, ascent /* 升序 */, descent /* 降序 */;
    cin >> source;
    source.insert(0, 4 - source.length(), '0');
    do {
        ascent = source;
        descent = source;
        sort(ascent.begin(), ascent.end(), cmp);
        sort(descent.begin(), descent.end());
        int result = stoi(ascent) - stoi(descent);
        source = to_string(result);
        source.insert(0, 4 - source.length(), '0');
        cout << ascent << " - " << descent << " = " << source << endl;
    } while (source != "6174" && source != "0000");
    return 0;
}

