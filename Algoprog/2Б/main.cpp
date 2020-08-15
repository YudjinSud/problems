#include <bits/stdc++.h>

#define int long long
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;

using namespace std;

int32_t main() {
    int n, k, s, count = -1;
    cin >> n >> k >> s;
    vi m(s);
    for(int i = 0; i < s; i++) cin >> m[i];

    while(n > 0) {
        n -= k;
        if(n <= 0) break;


    }

    cout << (lower_bound(m.begin(), m.end(), k)-1)[0];

    return 0;
}

