#include <bits/stdc++.h>

#define int long long
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::pair<int, int>> vpi;

using namespace std;

void f(char *kek) {
    char c;
    c = getc(stdin);
    (kek)[0] = c;
}

int32_t main() {
    char *kek = new char[5];
    f(kek);
    cout << kek;
    return 0;
}
