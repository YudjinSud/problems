#include <bits/stdc++.h>

#define int long long
#define eps 1e-5

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,c;
    cin >> a >> b >> c;
    if(c >= 0) {
        if(a == 0 && b != c*c) cout << "NO SOLUTION";
        else if(a == 0 && b == c*c) cout << "MANY SOLUTIONS";
        else if( (c*c - b) % a == 0) cout << (c*c - b)  /a;
        else cout << "NO SOLUTION";
    }
    else cout << "NO SOLUTION";
    return 0;
}