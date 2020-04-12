//
// Created by jun on 2020/5/11.
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
    分析: 因为所有长度都要串在一起，每次都等于(旧的绳子长度+新的绳子长度)/2, 所以越是早加入绳子长度中的段，越要对折的次数多，
    所以既然希望绳子长度是最长的，就必须让长的段对折次数尽可能的短。所以将所有段从小到大排序，然后从头到尾分别将每一段一次加入
    结绳的绳子中。
*/
int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1070.txt", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    int result = v[0];
    for (int i = 1; i < n; i++)
        result = (result + v[i]) / 2;
    printf("%d", result);
    return 0;
}

