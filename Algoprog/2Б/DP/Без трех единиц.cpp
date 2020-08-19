#include <bits/stdc++.h>

#define int long long
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;

using namespace std;


int32_t main() {
    int n;
    cin >> n;
    vi dp(n+1);
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;

    for(int i  =3; i <= n; i++) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    cout << dp[n];

    return 0;
}