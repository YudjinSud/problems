#include <bits/stdc++.h>

#define int long long
#define eps 1e-7

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    double  a, b, c;
    cin >> a >> b >> c;
    if(abs(a + b - c) <= eps)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}