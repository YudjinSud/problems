#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int hours = (n / 3600) % 24;
    int mins = ((n - hours* 3600) / 60) % (60*24);
    int sec = (n % 3600 % 60) % (60*60*24);

    char minsTens = mins / 10 + '0';
    char secTens = sec / 10 + '0';
    cout << hours << ":" << minsTens << mins%10 << ":" << secTens << sec%10;

    return 0;
}