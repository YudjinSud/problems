#include <bits/stdc++.h>

#define int long long
#define INF 100000007
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;

using namespace std;

const int sz = 100;
int vertices = 0;
vvi g(sz);
vi parent(sz);

vi bfs(int start) {
    queue<int>q;
    vi dist(vertices+1, INF);

    q.push(start);
    dist[start] = 0;
    while(q.size()) {
        int from = q.front();
        q.pop();
        for(auto to : g[from]) {
            if(dist[to] > dist[from] + 1) {
                dist[to] = dist[from] + 1;
                parent[to] = from;
                q.push(to);
            }
        }
    }
    return dist;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, v, u;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> v >> u;
        if(g[v].empty()) vertices++;
        if(g[u].empty()) vertices++;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    int start = 1;
    vi dist = bfs(start);
    for(int i = 1; i <= vertices; i++) {
        cout << start << " -> " << i << " = " << dist[i] << " path : ";
        vi path;
        path.push_back(i);
        for(int j = i; parent[j]; j = parent[j]) {
            path.push_back(parent[j]);
        }
        reverse(path.begin(), path.end());
        for(auto x : path) {
            cout << x << " -> ";
        }
        cout << "\b\b\b\b\n";

    }

    return 0;
}

//7
//1 2
//1 3
//2 3
//3 5
//3 4
//5 6
//6 7
