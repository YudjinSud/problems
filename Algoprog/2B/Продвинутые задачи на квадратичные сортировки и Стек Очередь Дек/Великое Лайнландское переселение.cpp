//
// Created by yudjin on 8/20/20.
//

#include <bits/stdc++.h>

#define int long long
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::pair<int, int>> vpi;

using namespace std;

int32_t main() {
    int n, sw;
    cin >> n;
    vi m(n), res(n, -1);
    for (int i = 0; i < n; i++) cin >> m[i];
    stack<int>st, positions;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && st.top() > m[i]) {
            res[positions.top()] = i;
            positions.pop();
            st.pop();
        }
        st.push(m[i]);
        positions.push(i);
    }
    for(int x : res) {
        cout << x << " ";
    }

    return 0;
}

