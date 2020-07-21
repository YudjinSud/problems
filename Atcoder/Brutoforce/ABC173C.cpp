#include <bits/stdc++.h>

#define int long long

using namespace std;

void print(vector<int> kek) {
    for (int i = 0; i < kek.size(); i++) {
        cout << kek[i] << " ";
    }
    cout << "\n";
}


void print(vector<vector<int>> kek) {
    for (int i = 0; i < kek.size(); i++) {
        print(kek[i]);
        cout << "\n";
    }
}

int getOne(vector<vector<int>> kek) {
    int res = 0;
    for (auto &i : kek) {
        for (int j = 0; j < i.size(); j++) {
            if (i[j] == 1) res++;
        }
    }
    return res;
}

vector<int> generateSubsets(int s, int n) {
    vector<int> subset;
    for (int i = 0; i < n; i++) {
        if ((s & (1 << i))) subset.push_back(i);
    }
    return subset;
}

vector<vector<int>> paintCols(vector<vector<int>> kek,
                              vector<int> cols) {
    for (auto x : cols) {
        for (int j = 0; j < kek.size(); j++) {
            kek[j][x] = 2;
        }
    }
    return kek;
}

vector<vector<int>> paintRows(vector<vector<int>> kek,
                              vector<int> rows) {
    for (auto x : rows) {
        for (int j = 0; j < kek[0].size(); j++) {
            kek[x][j] = 2;
        }
    }
    return kek;
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, w, k;
    char x;
    cin >> n >> w >> k;
    vector<vector<int>> kek;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < w; j++) {
            cin >> x;
            if (x == '.') temp.push_back(0);
            else if (x == '#') temp.push_back(1);
        }
        kek.push_back(temp);
    }
    int res = 0;
    if (getOne(kek) == k) res++;

    for (int i = 1; i < (1 << n); i++) {
        vector<vector<int>> kek2 = paintRows(kek,
                                             generateSubsets(i, n));
        if (getOne(kek2) == k) res++;
    }
    for (int i = 1; i < (1 << w); i++) {
        vector<vector<int>> kek2 = paintCols(kek,
                                             generateSubsets(i, w));
        if (getOne(kek2) == k) res++;
    }

    for (int i = 1; i < (1 << n); i++) {
        for (int j = 1; j < (1 << w); j++) {
            vector<vector<int>> kek2 = paintRows(kek,generateSubsets(i, n));
            kek2 = paintCols(kek2,generateSubsets(j, w));
            if (getOne(kek2) == k) {
                res++;
            }
        }
    }

    cout << res;

    return 0;
}