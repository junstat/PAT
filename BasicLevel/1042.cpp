//
// Created by jun on 2020/5/5.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    只统计字母, 且只考虑小写 -> int letters[26]
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1042.txt", "r", stdin);
#endif
    string s;
    getline(cin, s);
    int letters[26] = {0};
    for (char &c : s) {
        c = tolower(c);
        if (islower(c)) letters[c - 'a']++;
    }
    int maxCount = letters[0];
    char maxLetter = 'a';
    for (int i = 1; i < 26; i++)
        if (letters[i] > maxCount) {
            maxCount = letters[i];
            maxLetter = 'a' + i;
        }
    printf("%c %d", maxLetter, maxCount);
    return 0;
}

