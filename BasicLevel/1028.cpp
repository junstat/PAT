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
    出生日期直接比较字符串即可。
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1028.txt", "r", stdin);
#endif
    int n, cnt = 0;
    cin >> n;
    string name, birth, maxName, minName, maxBirth = "1814/09/06", minBirth = "2014/09/06";
    for (int i = 0; i < n; i++) {
        cin >> name >> birth;
        if (birth < "1814/09/06" || birth > "2014/09/06")
            continue;
        cnt++;
        if (birth >= maxBirth) {
            maxBirth = birth;
            maxName = name;
        }
        if (birth <= minBirth) {
            minBirth = birth;
            minName = name;
        }
    }
    cout << cnt;
    if (cnt) cout << " " << minName << " " << maxName;
    return 0;
}

