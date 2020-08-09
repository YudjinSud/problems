//
// Created by yudjin on 09.08.2020.
//

#include <bits/stdc++.h>

#define int long long
#define vi vector<int>

using namespace std;

int is_prime(int n) {
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}



int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin >> x;
    if(is_prime(x)) cout << "prime";
    else cout << "composite";

    return 0;
}

