//
// Created by yudjin on 13.08.2020.
//

#include <bits/stdc++.h>

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

void copyArr(vi &from, vi &to) {
    for(int i = 0; i < from.size(); i++) {
        to[i] = from[i];
    }
    for(int i = from.size(); i < to.size(); i++) {
        to[i] = 1;
    }
}

int is_prime(int x) {
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return 0;
    }
    return 1;
}

int sieve(int n) {
    int sz = 1000000;

    vi prime(sz, 1);
    vi primes;
    prime[0] = 0; prime[1] = 0;
    int i = 2;
    while(primes.size() < n) {

        if(i > sz) {
            sz*=2;
            vi tmp(sz);
            copyArr(prime, tmp);
            prime = tmp;
            i = sqrt(i);
            // if(!is_prime(i)) prime[i] = 0;
        }

        for (; i <= sz; i++) {
            if (prime[i]) {
                primes.push_back(i);
                for (int j = i * i; j <= sz; j += i) {
                    prime[j] = 0;
                }
            }
        }
    }

    //cout << primes[n-1];
    return primes[n-1];
}

void checker() {
    vi tests = {1,2,5,100, 500, 10000,100000, 1000000, 123456, 999999, 104729, 500000, 300000, 100001};

    for(int x : tests) {
        int res = sieve(x);
        cout << (is_prime(res) == 1 ? "YES" : "NO") << " " << x << " == " << res <<"\n";
    }
}

int32_t main() {

//    int n;
//    cin >> n;
    checker();
    return 0;
}

