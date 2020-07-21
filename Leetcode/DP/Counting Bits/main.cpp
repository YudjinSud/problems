#include <iostream>
#include <bits/stdc++.h>

using namespace  std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>res;
        res.push_back(0);
        int curr = 0;
        for(int i = 1; i <= num; i++) {
            if(i % 2 == 0) {
                res.push_back(res[i/2]);
                curr = res[i/2];
            }
            else {
                res.push_back(curr+1);
                curr++;
            }
        }
        return res;
    }
};

int main() {
    int x;
    cin >> x;
    Soulution sol;
    vector<int> res = sol.countBits(x);
    return 0;
}
