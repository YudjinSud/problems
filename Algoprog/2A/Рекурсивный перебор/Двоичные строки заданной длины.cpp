//
// Created by yudjin on 7/31/20.
//

#include <bits/stdc++.h>

#define int long long
#define sz 100

using namespace std;

int m[sz];
int n;

void check() {
    for(int i = 0; i < n; i++) {
        cout << m[i];
    }
    cout << "\n";
}

void find(int i) {
    if(i >= n) {
        check();
        return;
    }
    m[i] = 0;
    find(i+1);
    m[i] = 1;
    find(i+1);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    find(0);

    return 0;
}
