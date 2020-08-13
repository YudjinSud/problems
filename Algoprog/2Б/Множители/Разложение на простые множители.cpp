//
// Created by yudjin on 11.08.2020.
//

#include <bits/stdc++.h>

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

int least_divizor(int x) {
    for(int i = 2; i*i <=x; i++) {
        if(x % i == 0) return i;
    }
    return x;
}

void factor(int x) {
    while(x > 1) {
        int div = least_divizor(x);
        x /= div;
        cout << div;
        if(x != 1) {
            cout << "*";
        }
    }
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin >> x;
    factor(x);


    return 0;
}

