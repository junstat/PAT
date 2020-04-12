//
// Created by jun on 2020/7/18.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
   1. 输入 n;  nums -> vector;
   2. int covered[101] = {0}, 用作标记num是否被覆盖，1 -> 覆盖，0 -> 为覆盖，默认为0;
   3. 对nums排序, 输出covered[num] == 0的 num即可。

   关于打表下标越界的处理：
   1. 把数组长度定义长一些，如 10000
   2. 访问数组元素的时候判断是否越界。
 */

bool cmp(int a, int b) { return a > b; }

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1005.txt", "r", stdin);
#endif
    int n, num, firstPrint = 1;
    cin >> n;
    vector<int> nums(n);
    int covered[101] = {0};
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums[i] = num;
        while (num != 1) {
            if (num % 2 != 0) num = 3 * num + 1;
            num /= 2;
            if (num <= 100) {  // 打表在最后一个case出现段错误：数组下标越界
                if (covered[num]) break;
                covered[num] = 1;
            }
        }
    }
    sort(nums.begin(), nums.end(), cmp);
    for (int x: nums) {
        if (!covered[x]) {
            if (firstPrint) { cout << x; firstPrint = 0; }
            cout << " " << x;
        }
    }
    return 0;
}
