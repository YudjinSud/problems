//
// Created by yudjin on 8/6/20.
//

#include <bits/stdc++.h>

#define int long long
#define vi vector<int>
#define matrix vector<vector<int>>

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    matrix prices(n+1);
    matrix mat(n + 1, vector<int>(m+1));

    for (int i = 1; i <= n; i++) {
        vi tmp(m+1);
        for(int  j = 1; j <= m; j++) {
            cin >> tmp[j];
        }
        prices[i] = tmp;
    }

    for(int i = 1; i <= m; i++) mat[1][i] = mat[1][i-1] + prices[1][i];
    for(int i = 1; i <= n; i++) mat[i][1] = mat[i-1][1] + prices[i][1];

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            mat[i][j] = min(mat[i][j - 1], mat[i - 1][j]) + prices[i][j];
        }
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << " \n";
    }
    cout << mat[n][m];


    return 0;
}