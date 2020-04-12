//
// Created by jun on 2020/4/24.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;
/*
    1、形如xPATx都可以获得"答案正确"
    以下为正确:
    I.   PAT
    II.  APATA
    III. AAPATAA
    IV.  AAAPATAAA
    ==> 规律: 中间一个A，两边等量的A
    2、aPbTc是正确的，那么aPbATca也是正确的
    以I、II、III、IV、为例
    I.   PAT --> (as aPbTc)a=c=""，b="A" --> PAAT、PAAAAAT,中间多少个A均正确
    II.  APATA --> a=b=c="A" --> APAATAA(a="A", b=c="AA") --> APAAATAAA
    III. AAPATAA --> a=c="AA", b="A" --> AAPAATAAAA --> AAPAAATAAAAAA
    Summary:
    1、只能有1个P和1个T；
    2、P和T之间不能没有A；
    3、a * between(b, T) = after(c)
*/

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1003.txt", "r", stdin);
#endif
    int n, pLastIndex = 0, tLastIndex = 0;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        map<char, int> m;
        for (int j = 0; j < s.size(); j++) {
            m[s[j]]++;
            if (s[j] == 'P') pLastIndex = j;
            else if (s[j] == 'T') tLastIndex = j;
        }
        if (m['P'] == 1 &&
            m['A'] != 0 &&
            m['T'] == 1 &&
            m.size() == 3 &&
            tLastIndex - pLastIndex != 1 &&
            pLastIndex * (tLastIndex - pLastIndex - 1) == s.length() - tLastIndex - 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

