//
// Created by jun on 2020/5/6.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
/*
    1、关于格式验证: 读入字符串 -> a, 按"%lf"导出(sscanf)-> temp , 按"%.2f"导入(sprintf) -> b, 比对a 与 b是否一致
    2、平均值计算:
        2.1 cnt == 1 -> sum
        2.2 cnt > 1 -> sum / cnt
        2.3 cnt < 1 -> 无法计算
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1054.txt", "r", stdin);
#endif
    int n, cnt = 0;
    char a[50], b[50];
    double temp, sum = 0.0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp); /* 把a的内容以%lf的格式写入temp */
        sprintf(b, "%.2f", temp); /* 把temp的内容以%.2f的格式写入b */
        int flag = 0;
        for (int j = 0; j < strlen(a); j++)
            if (a[j] != b[j]) flag = 1;

        if (flag || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        } else {
            sum += temp;
            cnt++;
        }
    }
    if (cnt == 1)
        printf("The average of 1 number is %.2f", sum);
    else if (cnt > 1)
        printf("The average of %d numbers is %.2f", cnt, sum / cnt);
    else
        printf("The average of 0 numbers is Undefined");
    return 0;
}

