//
// Created by jun on 2020/7/21.
//
#include <iostream>
#include <vector>

using namespace std;

/*
   DA: 因为 0 < A, B < 10 ^ 10, 所以只能用string 存储 A, B, 进一步 char da, db。
   算法: 遍历 A , pa = 10 * pa + da - '0' if  A[i] == da; B 同理
        最后计算 pa + pb 输出即可
 */
int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1016.txt", "r", stdin);
#endif
    string A, B;
    char da, db;
    int pa = 0, pb = 0;
    cin >> A >> da >> B >> db;
    for (char a: A)
        if (a == da)
            pa = pa * 10 + da - '0';
    for (char b : B)
        if (b == db)
            pb = pb * 10 + db - '0';
    printf("%d", pa + pb);
    return 0;
}
