class Solution {
    int changingCoinsMemoization(vector<int> &coins, int amount, int ind, vector<vector<int>> &dp) {
        if(ind == 0) {
            return dp[ind][amount] = (amount % coins[ind] == 0) ? amount / coins[ind] : 1e9;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        
        int notTake = changingCoinsMemoization(coins, amount, ind - 1, dp);
        int take = INT_MAX;
        if(coins[ind] <= amount) {
            take = 1 + changingCoinsMemoization(coins, amount - coins[ind], ind, dp);
        }
        return dp[ind][amount] = min(take, notTake);
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = changingCoinsMemoization(coins, amount, n - 1, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};