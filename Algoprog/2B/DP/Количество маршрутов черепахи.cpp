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
    matrix mat(n+1);
    for(int i = 0; i <= n; i++) {
        vi tmp(m+1);
        mat[i] = tmp;
    }
    mat[0][1] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            mat[i][j] = mat[i][j-1] + mat[i-1][j];
        }
    }
    cout << mat[n][m];


    return 0;
}