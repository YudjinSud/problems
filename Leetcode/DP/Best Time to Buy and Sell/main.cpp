#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr = INT32_MAX, best = 0;
        for(int i = 0; i < prices.size(); i++) {
            curr = min(curr, prices[i]);
            best = max(best, prices[i] - curr);
        }
        return best;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1, 2};
    cout << sol.maxProfit(a);
    return 0;
}
