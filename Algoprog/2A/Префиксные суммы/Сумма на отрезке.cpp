//
// Created by yudjin on 9/10/20.
//
#include <bits/stdc++.h>

#define int long long
#define vi vector<int>

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vi a(n);
    vi sums(n);
    cin >> a[0];
    sums[0] = a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        sums[i] = sums[i - 1] + a[i];
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        if (l < 2) cout << sums[r - 1] << "\n";
        else
            cout << sums[r - 1] - sums[l - 2] << "\n";
    }

    return 0;
}