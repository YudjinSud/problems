//
// Created by yudjin on 8/19/20.
//

#include <bits/stdc++.h>

#define int long long

typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::pair<int,int>> vpi;

using namespace std;

int getPos(vi m, int k) {
    for(int i = 1; i < m.size(); i++) {
        if(m[i] > k) return i-1;
    }
    if(k >= m[m.size() -1]) return m.size() - 1;
    return -1;
}


int32_t main() {
    int d, k, n, count = 0, bak;
    cin >> d >> k >> n;
    bak = k;
    vi m(n);
    for(int i = 0; i < n; i++) cin >> m[i];

    int i = 0;


    cout << count;


    return 0;
}

