//
// Created by jun on 2020/5/1.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    分析: 关键求有多少层
        设有i层，上半部分(不含1个*)共有: 3 + 5 + ... + (2i+1) = (3 + 2i+1)*i/2=i*(i+2)个元素
    整个沙漏有2*i*(i+2)+1个元素
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1027.txt", "r", stdin);
#endif
    int N, row = 0;
    char c;
    cin >> N >> c;
    for (int i = 0; i < N; i++) {
        if ((2 * i * (i + 2) + 1) > N) {
            row = i - 1;
            break;
        }
    }
    for (int i = row; i >= 1; i--) {
        for (int k = row - i; k >= 1; k--) cout << " ";
        for (int j = i * 2 + 1; j >= 1; j--) cout << c;
        cout << endl;
    }
    for (int i = 0; i < row; i++) cout << " ";
    cout << c << endl;
    for (int i = 1; i <= row; i++) {
        for (int k = row - i; k >= 1; k--) cout << " ";
        for (int j = i * 2 + 1; j >= 1; j--) cout << c;
        cout << endl;
    }
    cout << (N - (2 * row * (row + 2) + 1));
    return 0;
}

