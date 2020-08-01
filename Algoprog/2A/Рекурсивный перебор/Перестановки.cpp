//
// Created by yudjin on 8/1/20.
//


#include <bits/stdc++.h>

#define int long long
#define sz 100

using namespace std;

int m[sz];
int visited[sz];
int k, n;

void check() {
    for (int i = 0; i < n; i++) {
        cout << m[i];
    }
    cout << "\n";

}

void find(int i) {
    if(i >= n) {
        check();
        return;
    }
    for(int j = 1; j <= n; j++) {
        if(visited[j] == 0) {
            m[i]= j;
            visited[j] = 1;
            find(i+1);
            visited[j] = 0;
        }
    }
}



int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(long long & i : visited) {
        i = 0;
    }
    cin >> n;
    find(0);
    return 0;
}
