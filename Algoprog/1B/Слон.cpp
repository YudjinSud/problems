#include <bits/stdc++.h>

#define int long long
#define eps 1e-5

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << ((a == c || b == d ) ? "YES" : "NO");
    return 0;
}
