//
// Created by yudjin on 8/19/20.
//

#include <bits/stdc++.h>

#define int long long

typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::pair<int, int>> vpi;

using namespace std;

vi tokenize(int x) {
    vi m;
    int k;
    while (x) {
        m.push_back(x % 10);
        x /= 10;
    }
    return m;
}


int32_t main() {
    int x;
    cin >> x;
    vi m = tokenize(x);

    sort(m.begin(), m.end());


    int i = 0;
    while (m[i] == 0) {
        i++;
    }
    swap(m[0], m[i]);


    for (int x : m) {
        cout << x;
    }

    return 0;
}

