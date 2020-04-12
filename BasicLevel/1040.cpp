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
    P  A  T
    countP: A之前P出现的次数； countT: A之后T出现的次数。
    result = sum(countP * countT)
    1、统计T个数 -> countT
    2、遍历输入字符串
        2.1 'P' -> countP++
        2.2 'T' -> countT--  因为T只能出现在A后
        2.3 'A' -> result += countP * countT

    注意: 大数阶乘，大数的排列组合等，一般都要求将输出结果对1000000007取模（取余）:
    1. 1000000007是一个质数（素数），对质数取余能最大程度避免冲突～
    2. int32位的最大值为2147483647，所以对于int32位来说1000000007足够大
    3. int64位的最大值为2^63-1，对于1000000007来说它的平方不会在int64中溢出
    所以在大数相乘的时候，因为(a∗b)%c=((a%c)∗(b%c))%c，所以相乘时两边都对1000000007取模，再保存在int64里面不会溢出
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1040.txt", "r", stdin);
#endif
    string source;
    int countP = 0, countT = 0, result = 0;
    cin >> source;
    for (char c: source) {
        if (c == 'T')
            countT++;
    }
    for (char c: source) {
        switch (c) {
            case 'P':
                countP++;
                break;
            case 'T':
                countT--;
                break;
            case 'A':
                result = (result + (countP * countT) % 1000000007) % 1000000007;
        }
    }
    printf("%d", result);
    return 0;
}

