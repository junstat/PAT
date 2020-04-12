//
// Created by jun on 2020/4/26.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    1、理解输入格式: 数字出现个数
    2、找到第一个不为0的数输出，为最高位；
    3、输出所有的0;
    4、升序输出其他数字；
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1023.txt", "r", stdin);
#endif
    int a[10], i;
    for (i = 0; i < 10; i++)
        cin >> a[i];
    for (i = 1; i < 10; i++) {
        if (a[i] != 0) {  // 找到第1个不为0的数
            cout << i;
            a[i]--;
            break;
        }
    }
    // 按顺序输出
    for (int j = 0; j < a[0]; j++) cout << 0;  // 先输出0
    for (; i < 10; i++)
        for (int k = 0; k < a[i]; k++)  // 若a[i]为0，不会进入循环
            cout << i;

    return 0;
}
