//
// Created by jun on 2020/4/24.
//

#include <iostream>
#include <string>

using namespace std;
/*
    1、数组自定义哈希表 str ，保存数字与拼音数字的对应；
    2、string读入s，逐位求和-> int res；
    3、int res->string num;
    4、逐位读取num，从str中取出结果并输出，注意格式。
 */


int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1002.txt", "r", stdin);
#endif
    string s;
    int res = 0;
    cin >> s;
    string str[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    for (int i = 0; i < s.length(); i++) {
        res += (s[i] - '0');
    }
    string num = to_string(res);
    for (int i = 0; i < num.length(); i++) {
        if (i != 0) cout << " ";
        cout << str[num[i] - '0'];
    }
    return 0;
}

