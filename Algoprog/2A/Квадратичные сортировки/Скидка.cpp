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
            if(res[j] < res[j+1]) {
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
    int  n;
    cin >>  n;
    int m[n];
    for(int i = 0; i < n; i++) cin >> m[i];

    int *res = bubbleSort(m, n);
    //print(res, n);
    int sum = 0, i = 0;

    while(n - i >= 2) {
        sum += res[i] + res[i+1];
        i+=3;
    }
    if(n - i == 1) sum += res[i];
    cout << sum;

    return 0;
}
