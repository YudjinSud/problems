//
// Created by yudjin on 8/19/20.
//

#include <bits/stdc++.h>

#define int long long

typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::pair<int,int>> vpi;

using namespace std;

int32_t main() {

    int n, skill, price, a;
    cin >> n >> skill;
    vpi m;
    while(n--) {
        cin >> price >> a;
        m.push_back(make_pair(price, a));
    }

    sort(m.begin(), m.end());

//    for(pair<int,int > kek : m) {
//        cout << "( " << kek.first << ", " << kek.second << " )\n";
//    }

    int count  = 0;
    for(int i = 0; i < m.size(); i++) {
        if(skill >= m[i].first) {
            skill+=m[i].second;
            count++;
        }
    }
    cout << count;


    return 0;
}

