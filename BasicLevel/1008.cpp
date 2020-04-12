//
// Created by jun on 2020/7/18.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
   1. input -> n, m, nums;
   2. reverse: begin ~ end; begin ~ begin+m; begin + m ~ end;

    坑: m > n
 */
int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1008.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    m = m % n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + m);
    reverse(nums.begin() + m, nums.end());
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << nums[i];
    }
    return 0;
}
