//
// Created by jun on 2020/7/18.
//

#include <iostream>

using namespace std;

/*
   1. isPrime -> 判断素数
   2. 遍历5~N, isPrime(i) && isPrime(i-2) -> 计数器+1;
 */

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1007.txt", "r", stdin);
#endif
    int N, cnt = 0;
    cin >> N;
    for (int i = 5; i <= N; i++) {
        if (isPrime(i) && isPrime(i - 2)) cnt++;
    }
    cout << cnt;
    return 0;
}
