//
// Created by jun on 2020/5/10.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
    注意3个点：
    1、如果已经是”#”了就不要继续下面的判断了，不然可能输出Wrong password: “#”
    2、如果密码错误并且达到了尝试的次数，是先输出Wrong password那句紧接着输出Account locked那句
    3、Wrong password: 后面有个空格～
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1067.txt", "r", stdin);
#endif
    string correctPW, temp;
    int n, cnt = 0;
    cin >> correctPW >> n;
    getchar();
    while (true) {
        getline(cin, temp);
        if (temp == "#") break;
        cnt++;
        if (temp == correctPW) {
            printf("Welcome in");
            break;
        } else {
            printf("Wrong password: %s\n", temp.c_str());
            if (cnt == n) {
                printf("Account locked");
                break;
            }
        }
    }
    return 0;
}


