#include <bits/stdc++.h>

//#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char s[1000000];
    scanf("%s", s);
    int offset = 0, len = strlen(s);
    if(s[0] == '@') offset++;
    for(int i = 1; i < len; i++) {
        s[i-offset] = s[i];
        if(s[i] == '@') offset++;
    }
    s[len - offset] = '\0';
    cout << s;

    return 0;
}