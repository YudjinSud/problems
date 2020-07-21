#include <bits/stdc++.h>

#define int long long
#define eps 1e-5

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k,t;
    cin >> k >> t;
    int period = t / k;
    int offset = t % k;
    period %= 2;
    k*= period;
    k-=offset;
    cout << abs(k);

    return 0;
}