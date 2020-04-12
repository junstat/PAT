//
// Created by jun on 2020/7/18.
//
#include <iostream>

using namespace std;

/*
   注意范围即可
 */
int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1011.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    long long a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (i) printf("\n");
        printf("Case #%d: %s", i+1, a + b > c ? "true" : "false");
    }
    return 0;
}

