#include <bits/stdc++.h>

#define int long long
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int>dp(amount+1, amount+1);
        
        dp[0] = 0;

        for(int i  = 1; i <= amount; i++) {
            for(int j : coins) {
				if(j <= i)
					dp[i] = dp[i] > (dp[i-j] + 1) ? dp[i-j] + 1 : dp[i];
            }
        }
         
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int32_t main() {
	
	Solution sol;
	
	vi coins = {1,2,5};
	cout << sol.coinChange(coins, 11);

    return 0;
}


