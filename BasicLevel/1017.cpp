//
// Created by jun on 2020/4/25.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
   1、 模拟手动除法的过程，每次用第一位去除以B，如果得到的商不是0就输出，否则就*10+下一位，直到最后的数为余数。
   注意：len(A) == 1的处理
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1017.txt", "r", stdin);
#endif
    string A;
    int B, remainder /* 余数 */ = 0, quotient /* 商 */ = 0;
    cin >> A >> B;
    int len = A.length();
    quotient = (A[0] - '0') / B;
    if ((quotient && len > 1) || len == 1)
        cout << quotient;
    remainder = (A[0] - '0') % B;
    for (int i = 1; i < len; i++) {
        remainder = remainder * 10 + (A[i] - '0');
        quotient = remainder / B;
        remainder %= B;
        cout << quotient;
    }
    cout << " " << remainder;
    return 0;
}

