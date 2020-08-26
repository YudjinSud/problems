#include <bits/stdc++.h>

#define int long long
#define INF 100000007

typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;

using namespace std;

int vertices = 0;

vi dijkstra(vvi g, vvi cost, int start) { // O(V^2 + E)
    vi dist(vertices + 1, INF);
    vi visited(vertices + 1);
    dist[start] = 0;

    for (int i = 1; i <= vertices; i++) {

        int closest_not_visited = -1;
        int min_cost = INF;
        for (int v = 1; v <= vertices; v++) {
            // ============== Выбираем ближайшую непосещённую ==============
            if (!visited[v] && dist[v] < min_cost) {
                min_cost = dist[v];
                closest_not_visited = v;
            }
        }
        visited[closest_not_visited] = 1;

        // ============== Релаксируем рёбра, идущие из неё ==============
        for (int i = 0; i < g[closest_not_visited].size(); i++) {
            dist[g[closest_not_visited][i]] = min(dist[g[closest_not_visited][i]],
                                                  dist[closest_not_visited] + cost[closest_not_visited][i]);
        }

    }
    return dist;
}




int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vvi g(100), costs(100);
    int n, v, u, cost;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v >> u >> cost;
        if (g[v].empty()) vertices++;
        if (g[u].empty()) vertices++;
        g[v].push_back(u);
        g[u].push_back(v);
        costs[v].push_back(cost);
        costs[u].push_back(cost);
    }

    vi dist = dijksta(g, costs, 1);

    for (int x : dist) {
        cout << x << " ";
    }


    return 0;

}

//3
//1 2 2
//2 3 2
//1 3 8

//6
//1 2 1
//2 3 4
//1 3 3
//2 4 2
//1 4 4
//3 4 1
