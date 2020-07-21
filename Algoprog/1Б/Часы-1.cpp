#include <bits/stdc++.h>

#define int long long
#define eps 1e-7

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    double  h, m, s;
    cin >> h >> m >> s;

    double hourDegreesInHour = 360 / 12;
    double hourDegreesInMin = hourDegreesInHour / 60;
    double hourDegreesInSec = hourDegreesInMin / 60;

    double res = h * hourDegreesInHour + m * hourDegreesInMin + s * hourDegreesInSec;
    cout << res;

    return 0;
}