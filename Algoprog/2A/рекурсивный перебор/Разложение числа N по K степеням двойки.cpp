//
// Created by yudjin on 7/31/20.
//

#include <bits/stdc++.h>

#define int unsigned long long
#define sz 100

using namespace std;

int m[sz];
int k, n;

void check() {
    // подходит ли такая комбинация степеней двойки
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += m[i];
    }
    if (sum == n) {
        for (int i = 0; i < k; i++) {
            cout << m[i] << " ";
        }
        cout << "\n";
    }
}

void find(int i) {
    if (i >= k) {
        check();
        return;
    }
    for(int j = 0; j < 64; j++) { // перебор по всем степеням двойки
        m[i] = (unsigned long)1 << j;
        find(i+1);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    find(0);
    return 0;
}
