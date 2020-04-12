//
// Created by jun on 2020/7/18.
//

#include <iostream>

using namespace std;

/*
   1. input n -> arrays nums;
   2. 输出 nums[2] 次 'B', nums[1] 次 'S', 1~nums[0],  because n < 1000;
 */
int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1006.txt", "r", stdin);
#endif
    int n, i = 0;
    cin >> n;
    int nums[3] = {0};
    while (n) {
        nums[i++] = n % 10;
        n /= 10;
    }
    for (i = 0; i < nums[2]; i++)
        cout << 'B';
    for (i = 0; i < nums[1]; i++)
        cout << 'S';
    for (i = 1; i <= nums[0]; i++)
        cout << i;
    return 0;
}

