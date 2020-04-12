//
// Created by jun on 2020/5/4.
//


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    1、input -> a/b c/d
    2、a/b + c/d -> ad+bc/bd
    3、a/b - c/d -> ad-bc/bd
    4、a/b * c/d -> ac / bd
    5、a/b / c/d -> ad / bc
    6、对于有理数 m/n 的处理
        6.1、m、n有一个为0， m = 0 -> m/n=0, n = 0 -> m/n = Inf
        6.2、确定符号，若m、n有一个为负，m/n为负 -> 输出 "(-"
        6.3、假分数，整数部分，x = abs(m) / abs(n)
        6.4、       分数部分, t = gcd(m - x*n,n), m /= t, n /= t.

    注意: 判断m和n是否异号千万不要写成判断m*n是否小于0，因为m*n的结果可能超过了long long int的长度，导致溢出大于0，如果这样写的话会有一个测试点无法通过～
*/

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

void func(long long m, long long n) {
    if (m * n == 0) {  /* m, n至少有一个为0 */
        printf("%s", n == 0 ? "Inf" : "0");
        return;
    }
    bool flag = ((m < 0 && n > 0) || (m > 0 && n < 0)); // 为什么不能用 m * n < 0 代替？
    m = abs(m);
    n = abs(n);
    long long x = m / n;
    printf("%s", flag ? "(-" : "");
    if (x) printf("%lld", x);
    if (m % n == 0) {
        if (flag) printf(")");
        return;
    }
    if (x) printf(" ");
    m -= x * n;
    long long t = gcd(m, n);
    m /= t;
    n /= t;
    printf("%lld/%lld%s", m, n, flag ? ")" : "");
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1034.txt", "r", stdin);
#endif
    long long a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    func(a, b); printf(" + "); func(c, d); printf(" = "); func(a * d + b * c, b * d); printf("\n");
    func(a, b); printf(" - "); func(c, d); printf(" = "); func(a * d - b * c, b * d); printf("\n");
    func(a, b); printf(" * "); func(c, d); printf(" = "); func(a * c, b * d); printf("\n");
    func(a, b); printf(" / "); func(c, d); printf(" = "); func(a * d, b * c); printf("\n");
    return 0;
}

