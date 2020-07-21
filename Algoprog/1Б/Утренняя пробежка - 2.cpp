#include <bits/stdc++.h>

#define int long long
#define eps 1e-7

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    double  x, y;
    cin >> x >> y;
    double sum = x;
    int res = 1;
    while(sum < y - eps) {
        x *= 1.7;
        sum += x;
        res++;
    }
    cout << res;


    return 0;
}