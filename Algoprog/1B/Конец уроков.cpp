#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    n;
    int evens = ((n-1)/2);

    int mins = 45 * n + 15 * evens + 5 * (n - 1- evens);

    cout << 9 + mins / 60 << " " << mins % 60;

    return 0;
}