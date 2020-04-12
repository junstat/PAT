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
    关于行数的确定：rows = N / 2 + N %2;
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1036.txt", "r", stdin);
#endif
    int N;
    char c;
    cin >> N >> c;
    int t = N / 2 + N % 2;
    for (int i = 0; i < N; i++)
        cout << c;
    cout << endl;
    for (int i = 0; i < t -2; i++) {
        cout << c;
        for (int j = 0; j < N - 2; j++)
            cout << " ";
        cout << c << endl;
    }
    for (int i = 0; i < N; i++)
        cout << c;
    return 0;
}

