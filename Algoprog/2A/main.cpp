#include <bits/stdc++.h>

#define int long long
#define vi vector<int>

using namespace std;

int is_par(char c) {
    return c == ')' || c == '(' || c == ']' || c == '[';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    getline(cin, s);

    int i = 0, res = 0;
    while(i < s.size()) {
        while(s[i] != ';' && s[i] != ':' && i < s.size()) i++;
        i++;
        while(s[i] == '-')i++;
        if(is_par(s[i])) {
           while(is_par(s[i])) i++;
           res++;
        }
    }
    cout << res;


    return 0;
}