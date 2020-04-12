//
// Created by jun on 2020/9/30.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("./input/1093.txt", "r", stdin);
#endif
    string input1, input2, combineStr;
    getline(cin, input1);
    getline(cin, input2);
    combineStr = input1 + input2;
    int hashTable[200] = {0};  /* 保存字符出现次数, e.g. 65 -> 'a' */
    for (char ch: combineStr){
        if (!hashTable[ch]) cout << ch;
        hashTable[ch] = 1;
    }
    return 0;
}