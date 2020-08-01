//
// Created by yudjin on 8/1/20.
//

#include <bits/stdc++.h>

#define int long long
#define sz 100

using namespace std;

int m[sz];
int k, n;

void check() {
    for (int i = 0; i < k; i++) {
        cout << m[i];
    }
    cout << "\n";

}

void find(int i) {
    if (i >= k) {
        check();
        return;
    }

    if (i == 0) {
        for (int j = 1; j <= n; j++) {
            m[i] = j;
            for(int l = 0; l < i; l++) {
                cout << " ";
            }
            cout << "m[" << i << "]= " << j << "\n";
            find(i + 1);
        }
        return;
    }

    for(int j = m[i-1] + 1; j <= n; j++) { // версия без ifa
        m[i]= j;
        for(int l = 0; l < i; l++) {
            cout << " ";
        }
        cout << "m[" << i << "]= " << j << "\n";
        find(i+1);
    }

//    for (int j = 1; j <= n; j++) {  // версия с if-ом
//        if (j > m[i - 1]) {
//            m[i] = j;
//            find(i + 1);
//        }
//    }
}

void find(int i, int x) {
    if (i >= k) {
        check();
        return;
    }
    for(int j = x; j <= n; j++) {
        m[i] = j;
        for(int l = 0; l < i; l++) {
            cout << " ";
        }
        cout << "m[" << i << "]= " << j << "\n";
        find(i+1, j+1);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    find(0,1 );
    return 0;
}
