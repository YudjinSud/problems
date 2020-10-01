//
// Created by yudjin on 9/10/20.
//

#include <bits/stdc++.h>

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

int32_t main() {
    int n;
    cin >> n;
    vi m(n);
    for(auto &it : m) cin >> it;
    vi sums(n);
    if(m[0] == 0) sums[0] = 1;

    for(int i = 1; i < n; i++) {
        sums[i] = sums[i-1] + (m[i] == 0 ? 1 : 0);
    }
    int k;
    cin >> k;
    while(k--) {
        int l, r;
        cin >> l >> r;
        if(l < 2) cout << sums[r-1] << " ";
        else cout << sums[r-1] - sums[l-2] << " ";
    }

    return 0;
}