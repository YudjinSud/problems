#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n;
    int dp[n];
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i < n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n-1];

    return 0;
}