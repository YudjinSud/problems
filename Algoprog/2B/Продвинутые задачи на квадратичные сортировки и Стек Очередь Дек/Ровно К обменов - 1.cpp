#include <bits/stdc++.h>

#define int long long
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::pair<int, int>> vpi;

using namespace std;

int n, k;

int bubbleSort(vi &m, int l) {
    int count = l;
    for (int i = 0; i < n - 1; i++) {
        if (count == 0) break;
        for (int j = 0; j < n - i - 1; j++) {
            if (m[j] < m[j + 1]) {
                if (count > 0) {
                    swap(m[j], m[j + 1]);
                    count--;
                }
            }
        }
    }
    return count;
}

int32_t main() {
    cin >> n >> k;

    vi m(n);
    for (int i = 0; i < n; i++) m[i] = i + 1;

    bubbleSort(m, k);

    for (int x : m) {
        cout << x << " ";
    }

    return 0;
}


