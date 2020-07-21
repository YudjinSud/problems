#include <bits/stdc++.h>

#define int long long
#define eps 1e-14

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double res = 1;
    double fac = 1;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        fac *= (double)i;
        res += 1 / fac;
    }
    cout.precision(10);
    cout << res;
    return 0;
}