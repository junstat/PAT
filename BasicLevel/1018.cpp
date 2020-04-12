//
// Created by jun on 2020/4/25.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
        乙: B    C   J
  甲: B     \    甲  乙
      C     乙   \   甲
      J     甲   乙   \
Summary:
    甲win: (B, C)、(C, J)、(J, B)
    乙win: (B, J)、(C, B)、(J, C)
*/


int maxWinIndex(const int symbols[]) {
    int maxTimes = 0;
    int res = 0;
    for (int i = 0; i < 3; i++) {
        if (symbols[i] > maxTimes) {
            maxTimes = symbols[i];
            res = i;
        }
    }
    return res;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1018.txt", "r", stdin);
#endif
    int N;
    cin >> N;
    char j, y;
    int jWin = 0, yWin = 0; /* win times */
    int jSymbol[3] = {0}, ySymbol[3] = {0}; /* win symbol : B C J */
    for (int i = 0; i < N; i++) {
        cin >> j >> y;
        if (j == 'B' && y == 'C') {
            jWin++;
            jSymbol[0]++;
        } else if (j == 'B' && y == 'J') {
            yWin++;
            ySymbol[2]++;
        } else if (j == 'C' && y == 'J') {
            jWin++;
            jSymbol[1]++;
        } else if (j == 'C' && y == 'B') {
            yWin++;
            ySymbol[0]++;
        } else if (j == 'J' && y == 'B') {
            jWin++;
            jSymbol[2]++;
        } else if (j == 'J' && y == 'C') {
            yWin++;
            ySymbol[1]++;
        }
    }
    cout << jWin << " " << N - jWin - yWin << " " << yWin << "\n"
         << yWin << " " << N - jWin - yWin << " " << jWin << "\n";
    string str = "BCJ";
    cout << str[maxWinIndex(jSymbol)] << " " << str[maxWinIndex(ySymbol)];
    return 0;
}

