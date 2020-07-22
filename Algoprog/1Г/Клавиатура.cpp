//
// Created by yudjin on 7/22/20.
//

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, x;
    cin >> n;
    int keyboard[n];
    for (int i = 0; i < n; i++) {
        cin >> keyboard[i];
    }

    cin >> k;

    for(int i = 0; i < k; i++) {
        cin >> x;
        keyboard[x-1]--;
    }
    for(int i = 0; i < n; i++) {
        if(keyboard[i] < 0) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}