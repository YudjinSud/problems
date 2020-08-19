//
// Created by yudjin on 13.08.2020.
//
#include <bits/stdc++.h>

#define int long long
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;

using namespace std;

int is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int sieve(int n) {
    int sz = 100000;
    int startSz = 0;
    vi prime(sz, 1);
    vi primes;
    prime[0] = 0;
    prime[1] = 0;
    int i = 2;
    while (primes.size() < n) {
        if (i * 1ll * i >= sz) {
            startSz = sz;
            sz *= 2;
            prime.clear();
            prime = vi(sz, 1);
            for (int x : primes) {
                if (x * 1ll * x <= sz)
                    for (int j = x * x; j <= sz; j += x) {
                        prime[j] = 0;
                    }
            }
        }

        for (; i * i <= sz; i == 2 ? i++ : i += 2) {
            if (prime[i]) {
                if (i * 1ll * i <= sz)
                    for (int j = i * i; j <= sz; j += i) {
                        prime[j] = 0;
                    }
            }
        }

        for (int j = startSz; j < sz; j++) {
            if (prime[j])
                primes.push_back(j);
        }

    }
//    for(int x : primes) {
//        cout << x << " ";
//    }

    return primes[n - 1];
}

void checker() {
    vi tests = {1, 2, 5, 100, 500, 10000, 100000, 1000000, 123456, 999999, 104729, 500000, 300000, 100001};

    for (int x : tests) {
        int res = sieve(x);
        cout << (is_prime(res) == 1 ? " YES" : " NO") << " " << x << " == " << res << "\n";
    }
}

int32_t main() {

    int n;
    cin >> n;
    cout << sieve(n);
//    checker();
    return 0;
}


