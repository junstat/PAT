//
// Created by jun on 2020/7/18.
//

#include <iostream>

using namespace std;

/*
   1. (ax^b)' = a*b*x^(b-1): a b -> a*b (b-1) if b
   2. 0 0 if 零多项式
 */

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1010.txt", "r", stdin);
#endif
    int a, b, notFirstPrint = 0;
    while (cin >> a >> b)
        if (b) {
            if (notFirstPrint) cout << " ";
            cout << a * b << " " << b - 1;
            notFirstPrint = 1;
        }
    if (!notFirstPrint) cout << "0 0";
    return 0;
}
