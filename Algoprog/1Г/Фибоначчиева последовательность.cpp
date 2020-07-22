#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int dp[n+1];
    cin >> dp[n-1];
    cin >> dp[n];

    for(int i = n-2; i >= 0; i--) {
        dp[i] = dp[i+2] - dp[i+1];
    }

    cout << dp[0] << " " << dp[1];
    return 0;
}