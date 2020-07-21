#include <bits/stdc++.h>

#define int long long
#define eps 1e-5

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double xSuff, ySuff, zSuff;
    cin >> xSuff >> ySuff >> zSuff;
    int n;
    double kol;
    cin >> n;
    double x, y, z;

    while(n--) {
        cin >> x >> y >> z >> kol;
        xSuff -= x * kol;
        ySuff -= y * kol;
        zSuff -= z * kol;
    }
    if((xSuff < eps) &&  (ySuff < eps) &&  (zSuff < eps))
        cout << "YES\n";
    else
        cout << "NO\n";


    return 0;
}