//
// Created by yudjin on 7/28/20.
//

#include <bits/stdc++.h>

#define int long long

using namespace std;


int checkSymmetry(int m[], int start, int n) {
    int res = 1;
    for(int i = 0; i < n - start; i++) {
        if(m[start + i] != m[n - i - 1]) {
            res = 0;
            break;
        }
    }
    return res;
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, res = 0;
    cin >> n;
    int m[2 * n];

    for (int i = 0; i < n; i++) cin >> m[i];



    for(int i = 0; i < n; i++) {
        if(checkSymmetry(m, i, n)) {
            res = i;
            break;
        }
    }

    cout << res << "\n";
    if (res != 0) {
        for (int i = res-1; i >= 0; i--) {
            cout << m[i] << " ";
        }
    }


    return 0;
}

