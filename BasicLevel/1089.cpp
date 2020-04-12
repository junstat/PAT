//
// Created by jun on 2020/4/20.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("./input/1089.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<int> inputWords(n+1);
    for (int i = 1; i <= n; i++) cin >> inputWords[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vector<int> lie /* 保存说谎人下标 */, status(n + 1, 1) /* 保存身份: -1 狼人, 1 好人 */;
            status[i] = status[j] = -1;
            for (int k = 1; k <= n; k++)
                if (inputWords[k] /* k说的内容 */ * status[abs(inputWords[k])] /* k说的人实际身份 */ < 0) lie.push_back(k);
            if (lie.size() == 2 && status[lie[0]] + status[lie[1]] == 0) { /* 恰好有2人说谎，1好人，1狼人 */
                cout << i << " " << j;
                return 0;
            }
        }
    }
    cout << "No Solution";
    return 0;
}
