//
// Created by jun on 2020/9/30.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("./input/1091.txt", "r", stdin);
#endif
    int m, num;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int existSolution = 0;
        cin >> num;
        for (int n = 1; n < 10; n++) {
            int nSquare = n * num * num;
            string nSquareStr = to_string(nSquare), numStr = to_string(num);
            string tailStr = nSquareStr.substr(nSquareStr.length() - numStr.length());
            if (tailStr == numStr) {
                printf("%d %d\n", n, nSquare);
                existSolution = 1;
                break;
            }
        }
        if (!existSolution) printf("No\n");
    }
    return 0;
}