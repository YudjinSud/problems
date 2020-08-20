//
// Created by yudjin on 8/20/20.
//

#include <bits/stdc++.h>

#define int long long
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::pair<int, int>> vpi;

using namespace std;

int32_t main() {
    int n;
    cin >> n;
    vvi dp(n+1, vi(11, 1));
    dp[1][0] = 0;
    for(int i = 2; i <=n; i++) {
        for(int j = 1; j <= 8; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
        }
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][9] = dp[i-1][8] + dp[i-1][9];
    }
    int sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += dp[n][i];
    }
    cout << sum;
    return 0;
}

