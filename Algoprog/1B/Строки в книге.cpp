#include <bits/stdc++.h>

#define int long long
#define eps 1e-5

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k; // n - количество строк на странице, k - номер строки
    cin >> n >> k;
    int page = (k - 1) / n + 1;
    int str = k - (page-1)*n;
    cout << page << " " << str;
    return 0;
}