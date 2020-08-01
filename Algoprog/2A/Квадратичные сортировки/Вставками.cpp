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


int* insertionSort(int m[], int n) {
    int *res = m, ins = 0;
    for(int i = 0; i < n; i++) {
        int j = i+1;
        while(j > 0 && m[j] < m[j-1]) {
            swap(m[j], m[j-1]);
            j--;
            ins = 1;
        }
        if(ins == 1) {
            print(res, n);
        }
        ins = 0;
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
    int *res = insertionSort(m, n);
    //print(res, n);
    return 0;
}
