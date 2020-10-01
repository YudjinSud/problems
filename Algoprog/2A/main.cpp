#include <bits/stdc++.h>

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

vi factor(int x) {
    int j = 2;
    vi res;
    while (j * j <= x) {
        while (x % j == 0) {
            res.push_back(j);
            x /= j;
        }
        j++;
    }
    if (x != 1) res.push_back(x);
    return res;
}

int32_t main() {
    int n;
    cin >> n;
    vi f = factor(n);

    set<int> s;
    for (auto x : f) s.insert(x);

    int y = 1;
    for (auto x : s) y *= x;
    if (y == n) cout << n;
    else if (s.find(n) != s.begin()) {
        for (int i = 1; i < 40; i++) {
            if ((int) pow(y * i, y * i) % n == 0) {
                cout << y * i;
                return 0;
            }
        }
        cout << y;
    } else cout << n;

    return 0;
}