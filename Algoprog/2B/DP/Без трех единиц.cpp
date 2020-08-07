//
// Created by yudjin on 8/6/20.
//

#include <bits/stdc++.h>

#define int long long
#define vi vector<int>

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vi dp(n+1), eds(n+1);

    for(int i = 3; i <= n; i++) {
        eds[i] = eds[i-1] + 1;
    }

    for(int i = 0; i <= n; i++) {
        dp[i] = (1 << i ) - eds[i];
    }
    cout << dp[n];

    return 0;
}