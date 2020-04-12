//
// Created by jun on 2020/5/6.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*
    z1 = r1[cos(p1)+i*sin(p1)]
    z2 = r2[cos(p2)+i*sin(p2)]
    z1*z2 = r1r2[(cos(p1)cos(p2)-sin(p1)sin(p2)) + i(cos(p1)sin(p2)+sin(p1)cos(p2))]
    ==> A = r1r2[cos(p1)*cos(p2) - sin(p1)sin(p2)]
        B = r1r2[cos(p1)*sin(p2) + sin(p1)cos(p2)]
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1051.txt", "r", stdin);
#endif
    double r1, p1, r2, p2;
    cin >> r1 >> p1 >> r2 >> p2;
    double A, B;
    A = r1 * r2 * (cos(p1) * cos(p2) - sin(p1) * sin(p2));
    B = r1 * r2 * (cos(p1) * sin(p2) + sin(p1) * cos(p2));
    if (A + 0.005 >= 0 && A < 0) /* [-0.005, 0) */
        printf("0.00");
    else
        printf("%.2f", A);
    if (B > 0)
        printf("+%.2fi", B);
    else if (B + 0.005 >= 0 && B < 0) /* [-0.005, 0) */
        printf("+0.00i");
    else
        printf("%0.2fi", B);
    return 0;
}

