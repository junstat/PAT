//
// Created by jun on 2020/7/18.
//
#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
   input word -> stack words;
 */

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1009.txt", "r", stdin);
#endif
    stack<string> words;
    string word;
    int notFirstPrint = 0;
    while (cin >> word)
        words.push(word);
    while (!words.empty()) {
        if (notFirstPrint) cout << " ";
        cout << words.top();
        words.pop();
        notFirstPrint = 1;
    }
    return 0;
}
