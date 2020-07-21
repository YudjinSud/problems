#include <bits/stdc++.h>

#define int long long
#define eps 1e-5

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int p1 = ((a + 1)/ 2);
    int p2 = ((b + 1)/ 2);
    int p3 = ((c + 1)/ 2);
    cout << p1 + p2 + p3;
    return 0;
}