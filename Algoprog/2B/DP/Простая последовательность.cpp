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
    vi dp(2*n+1);
    dp[0] = 1; dp[1] = 1;

    for(int i = 1; i < n; i++) {
        dp[2*i] = dp[i] + dp[i-1];
        dp[2*i +1] = dp[i] - dp[i-1];
    }
    for(int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
    cout << dp[n];
    return 0;
}