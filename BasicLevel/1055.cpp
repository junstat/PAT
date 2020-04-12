//
// Created by jun on 2020/5/6.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
    注意： 中间位置为 m/2+1，其中 m 为该排人数，除法向下取整
    每排人数的确定:  m = n - n / k * (k-1) ,第1排; m = n / k， else;
    每排位置的确定: 先中间，再左边，最后右边
*/
struct node {
    string name;
    int height;
};

int cmp(struct node a, struct node b) {
    return a.height != b.height ? a.height > b.height : a.name < b.name;
}


int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1055.txt", "r", stdin);
#endif
    int n, k, m;
    cin >> n >> k;
    vector<node> stu(n);
    for (int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].height;
    }
    sort(stu.begin(), stu.end(), cmp);
    int t = 0, row = k;
    while (row) {
        if (row == k)
            m = n - n / k * (k - 1);
        else
            m = n / k;
        vector<string> ans(m);
        ans[m / 2] = stu[t].name;
        // 左边一列
        int j = m / 2 - 1;
        for (int i = t + 1; i < t + m; i += 2)
            ans[j--] = stu[i].name;
        // 右边一列
        j = m / 2 + 1;
        for (int i = t + 2; i < t + m; i += 2)
            ans[j++] = stu[i].name;
        // 输出当前排
        cout << ans[0];
        for (int i = 1; i < m; i++)
            cout << " " << ans[i];
        cout << endl;
        t += m;
        row--;
    }


    return 0;
}

