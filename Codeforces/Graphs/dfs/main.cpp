#include <bits/stdc++.h>

#define int long long
#define mod 1000000007

using namespace std;

#define sz 10

vector<int> hotels;


int getV(int v, vector<int> g) {
    for(int i = 1; i <= g.size(); i++) {
        if (g[i] == v) return i;
    }
    return 0;
}

void print( vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}

vector<int> solve(int v, const vector<int>& g) {
    vector<int> p;
    p.push_back(v);
    int prev = getV(v, g);
    while(getV(prev, g) != 0) {
        prev = getV(prev, g);
        p.push_back(prev);
    }
    return p;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n;
    vector<int> g(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x) hotels.push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x) {
            g[x] = i;
            g[i] = x;
        }
    }
    int res = 0;
    vector<int>rese, maxres;

    for(int i = 0; i < hotels.size(); i++)
    {
        rese = solve(hotels[i], g);
        print(rese);
        if(rese.size() > res) {
            maxres = rese;
        }
    }
    cout << maxres.size() << '\n';
    reverse(maxres.begin(), maxres.end());
    print(maxres);

    return 0;
}