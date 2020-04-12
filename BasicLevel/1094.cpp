//
// Created by jun on 2020/9/30.
//


#include <iostream>
#include <string>

using namespace std;

bool isPrime(int n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("./input/1094.txt", "r", stdin);
#endif
    int l, k;
    string inputString;
    cin >> l >> k >> inputString;
    for (int i = 0; i <= l - k; i++){
        string partString = inputString.substr(i, k);
        int num = stoi(partString);
        if (isPrime(num)) {
            cout << partString;
            return 0;
        }
    }
    cout << "404\n";
    return 0;
}