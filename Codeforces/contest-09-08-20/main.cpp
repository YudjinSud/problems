#include <bits/stdc++.h>

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

int n, m;
vvi mat(100, vi(100));


int dfs(int i, int j) {
    int sum = 0;
    vector<char> path;
    while (mat[i][j] != -1 && (j < m && i < n)) {
        path.push_back(mat[i][j] == 1 ? 'D' : 'R');
        if (mat[i][j] == 1) {
            if (i + 1 == n) {
                j++;
                sum++;
                continue;
            }
        } else {
            if (j + 1 == m) {
                i++;
                sum++;
                continue;
            }
        }
        if (mat[i][j] == 1) i++;
        else j++;
    }
    for(char l : path) {
        cout << l << " ";
    }
    cout << "\n";
    return sum;
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                mat[i][j] = c == 'R' ? 0 : 1;
                if (c == 'C') mat[i][j] = -1;
            }
        }

        int sum = 0, glSum = 0;
        int r, d;
        sum = dfs(0, 0);
        cout << sum << "\n";

        for (int k = 0; k < n; k++) {
            for (int l = 0; l < m; l++) {
                sum = max(sum, dfs(k, l)); // самый неудобный случай
            }
        }
        cout << sum << "\n";
    }


    return 0;
}

//1
//3 3
//RRD
//DDR
//RRC

//1
//1 4
//DDDC

//1
//6 9
//RDDDDDRRR
//RRDDRRDDD
//RRDRDRRDR
//DDDDRDDRR
//DRRDRDDDR
//DDRDRRDDC