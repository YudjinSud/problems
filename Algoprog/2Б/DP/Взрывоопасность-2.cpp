//
// Created by yudjin on 8/19/20.
//
#include <bits/stdc++.h>

#define int long long
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;

using namespace std;


int32_t main() {
    int n;
    cin >> n;
    vvi dp(n+1, vi(4));
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i][3] = dp[i-1][1] + dp[i-1][2];
        dp[i][1] = dp[i-1][1] + dp[i-1][2] + dp[i-1][3];
        dp[i][2] = dp[i][1];
    }

    cout << dp[n][1] + dp[n][2] + dp[n][3];

    return 0;
}
