//
// Created by jun on 2020/7/19.
//

#include <iostream>
#include <vector>

using namespace std;

/*
   1. 素数判断
   2. num in [2, +inf), cnt计数素数个数, num -> res, if M <= cnt <= N
   3. 重置cnt计数器，每10个换行
 */

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1013.txt", "r", stdin);
#endif
    int m, n, num = 2, cnt = 0;
    cin >> m >> n;
    vector<int> nums;
    while (cnt < n) {
        if (isPrime(num)) {
            cnt++;
            if (cnt >= m) nums.push_back(num);
        }
        num++;
    }
    cnt = 0;
    for (int x: nums){
        cnt++;
        if (cnt % 10 != 1) printf(" ");
        printf("%d", x);
        if (cnt % 10 == 0) printf("\n");
    }
    return 0;
}
