//
// Created by yudjin on 8/2/20.
//

#include <bits/stdc++.h>

#define int long long

using namespace std;


int isDigit(char c) {
    if(c - '0' >= 0 && c - '0' <= 9) return 1;
    return 0;
}


int myPow(int d, int deg) {
    int res = 1;
    for(int i = 1; i <= deg; i++) {
        res*=d;
    }
    return res;
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, res = "YES";
    getline(cin, s);
    for(int i = 0; i < s.size(); i++) {
        int digit = 0, j = i;
        while(isDigit(s[j])) {
            int c = s[j] - '0';
            if(c == 0) {
                res = "NO";
                break;
            }
            digit += c * myPow(10, j - i);
            j++;
        }
        if(digit > 5 ) {
            res = "NO";
            break;
        }
    }
    cout << res;

    return 0;
}
