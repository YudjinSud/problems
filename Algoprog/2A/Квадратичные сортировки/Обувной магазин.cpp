//
// Created by yudjin on 8/1/20.
//

#include <bits/stdc++.h>

#define int long long

using namespace std;


void print(int *m, int n) {
    for(int i = 0; i < n; i++) {
        cout << m[i] << " ";
    }
    cout << "\n";
}


int* bubbleSort(int m[], int n) {
    int *res = m;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(res[j] > res[j+1]) {
                swap(res[j], res[j+1]);
            }
        }
    }
    return res;
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, n;
    cin >> x >> n;
    int m[n];
    for(int i = 0; i < n; i++) cin >> m[i];

    int *res = bubbleSort(m, n);

    int mInd = 0;
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        if(res[i] >= x) {
            mInd = i;
            cnt++;
            break;
        }
    }
    if(cnt) {
        for (int i = mInd + 1; i < n; i++) {
            if (res[i] - res[mInd] >= 3) {
                cnt++;
                mInd = i;
            }
        }
    }
    cout << cnt;
    return 0;
}
