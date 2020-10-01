//
// Created by yudjin on 9/10/20.
//

#include <bits/stdc++.h>

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

int32_t main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vvi a(n + 1, vi(m + 1));
    vvi sums(n + 1, vi(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        sums[1][i] = sums[1][i - 1] + a[1][i];
    }

    for (int i = 1; i <= m; i++) {
        sums[i][1] = sums[i - 1][1] + a[i][1];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            sums[i][j] = sums[i - 1][j] + sums[i][j - 1] + a[i][j] - sums[i - 1][j - 1];
        }
    }

    while (k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sums[x2][y2] - sums[x1 - 1][y2] - sums[x2][y1 - 1] + sums[x1 - 1][y1 - 1] << "\n";
    }

    return 0;
}