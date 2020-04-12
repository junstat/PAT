//
// Created by jun on 2020/5/17.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1076.txt", "r", stdin);
#endif
    string s;
    while (cin >> s)
        if (s.size() == 3 && s[2] == 'T') cout << s[0] - 'A' + 1;
    return 0;
}

