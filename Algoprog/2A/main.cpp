
#include <bits/stdc++.h>

#define int long long
#define sz 100

using namespace std;

int m[sz];
int k, n;

void check() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (m[i] == 1) cnt++;
    }
    if (cnt == k) {
        for (int i = 0; i < n; i++) {
            cout << m[i];
        }
        cout << "\n";
    }
}

void find(int i) {
    if (i >= n) {
        check();
        return;
    }
    for(int j = 0; j < k; j++) {
        m[i] = 0;
    }
    m[i] = 0;
    find(i + 1);
    m[i] = 1;
    find(i + 1);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    find(0);
    return 0;
}
