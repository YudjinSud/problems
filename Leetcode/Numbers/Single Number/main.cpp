#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define int long long

class Solution {
public:
    long long mod;
    Solution(long long x) : mod(x) {}


    int getPhi (int n) {
        int result = n;
        for (int i=2; i*i<=n; ++i)
            if (n % i == 0) {
                while (n % i == 0)
                    n /= i;
                result -= result / i;
            }
        if (n > 1)
            result -= result / n;
        cout << result << "\n";
        return result;
    }

    long long bin_pow(long long base, long long p) {
        if (p == 1) {
            return base;
        }

        if (p % 2 == 0) {
            long long t = bin_pow(base, p / 2);
            return t * t % mod;
        } else {
            return bin_pow(base, p - 1) * base % mod;
        }
    }

    long long inverse_element(long long x) {
        long long phi = getPhi(mod);
        return bin_pow(x,phi-1);
    }

//(a / b) mod m
    long long divide(long long a, long long b) {
        long long c = inverse_element(b);
        return a * c % mod;
    }
};

int32_t main() {
    long long a, b, m;
    cin >> a >> b >> m;
    Solution *sol = new Solution(m);
    cout << sol->divide(a, b);
    return 0;
}
