#include <bits/stdc++.h>

#define int long long

typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::pair<int, int>> vpi;

using namespace std;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int32_t main() {
    int x, m = -1;
    pair<int, int> p;
    cin >> x;
    for (int i = 1, j = x - 1; i <= j; i++, j--) {
        int g = gcd(i, j);
        if (g > m) {
            m = gcd(i, j);
            p = make_pair(i, j);
        }
    }
    cout << p.first << " " << p.second;
    return 0;
}

