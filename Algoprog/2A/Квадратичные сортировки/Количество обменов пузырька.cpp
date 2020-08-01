//
// Created by yudjin on 8/1/20.
//


#include <bits/stdc++.h>

#define int long long

using namespace std;


int* bubbleSort(int m[], int n, int *count) {
    int *res = m;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(res[j] > res[j+1]) {
                swap(res[j], res[j+1]);
                (*count)++;
            }
        }
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
    int *res = bubbleSort(m, n, &count);
    cout << count;
    return 0;
}
