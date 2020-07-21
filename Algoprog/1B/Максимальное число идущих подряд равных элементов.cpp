#include <bits/stdc++.h>

#define int long long

#define start 1605
#define testsN 10

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x, prev = 0, res = 0, cnt=0;
    while(cin >> x && x != 0) {
        if(x == prev) {
            cnt++;
        }
        else {
            res = max(cnt, res);
            cnt = 1;
        }
        prev = x;
    }

    cout << max(res,cnt);
    return 0;
}