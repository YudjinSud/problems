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


int getMax(int m[] ,int start, int n) {
    int mInd = start;
    for(int i = start; i <= n; i++) {
        if(m[mInd] < m[i]) {
            mInd = i;
        }
    }
    return mInd;
}

int* choiceSort(int m[], int n) {
    int indMax = 0;
    int *res = m;
    for(int i = n - 1; i >= 0; i--){
        indMax = getMax(m, 0, i);
        swap(res[i], res[indMax]);
        //print(res, n);
    }
    return res;
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, count = 0;
    cin >> n;
    int m[n];
    for(int i = 0; i < n; i++) cin >> m[i];
    int *res = choiceSort(m, n);
    print(res, n);
    return 0;
}
