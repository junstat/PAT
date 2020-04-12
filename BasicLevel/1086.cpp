//
// Created by jun on 2020/4/20.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1086.txt", "r", stdin);
#endif
    int a, b;
    string ans;
    scanf("%d %d", &a, &b);
    ans = to_string(a * b);
    reverse(ans.begin(), ans.end());
    printf("%d", stoi(ans));
    return 0;
}

