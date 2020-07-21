#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    int sum = 0;
    getline(cin, s);

    for(int i = 0; i < s.size(); i++) {
        while(i < s.size()-1 && s[i] == ' ') {
          i++;
        }
        if( i > 0 && s[i-1] == ' ') {
            cout << ' ';
        }
        cout << s[i];
    }

    return 0;
}