#include <bits/stdc++.h>

#define int long long

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, res = 0;
    while ((cin >> x) && x != 0) {
        if (x % 2 == 0)
            res++;
    }
    cout << res;

    return 0;
}
