#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    getline(cin, s);

    // Подозреваю, что оба решения не достаточно оптимальны, и можно это сделать
    // за О(1) по памяти и О(n) по времени?

    for(int i = 0; i < s.size(); i++) {
        for(int j = i+1; j < s.size(); j++) {
            if(s[i] == s[j]) {
                cout << s[i];
                return 0;
            }
        }
    }

    map<int, int>m;
    for(char i : s) {
        m[i]++;
    }
    for(char i : s) {
        if(m[i] == 2) {
            cout << i;
            break;
        }
    }

    return 0;
}