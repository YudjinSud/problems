#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, l, n;
    cin >> a >> b >> l >> n;
    cout << a * (2*n - 1) + b * 2*(n-1) + 2*l;

    return 0;
}