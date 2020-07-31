//
// Created by yudjin on 7/31/20.
//

#include <bits/stdc++.h>

#define int long long
#define sz 100

using namespace std;

int m[sz];
int k, n;

void check() {
    for(int i = 0; i < k; i++) {
        cout << m[i];
    }
    cout << "\n";
}

void find(int i) {
    if(i >= k) {
        check();
        return;
    }
    for(int j = 0; j < n; j++) { // для бинарного случая можно было обойтись без цикла, теперь же
        // цифр столько - какова СС = n.
        m[i] = j;
        find(i+1);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> n;
    find(0);

    return 0;
}
