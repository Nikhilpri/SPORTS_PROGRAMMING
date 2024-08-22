class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

        // Base case for the first type of coin
        for (int amt = 0; amt <= amount; amt += coins[0]) {
            dp[0][amt] = amt / coins[0];
        }

        for (int ind = 1; ind < n; ind++) {
            for (int amt = 0; amt <= amount; amt++) {
                int notTake = dp[ind - 1][amt];
                int take = (amt >= coins[ind]) ? dp[ind][amt - coins[ind]] + 1 : 1e9;
                dp[ind][amt] = min(take, notTake);
            }
        }

        int ans = dp[n - 1][amount];
        return ans >= 1e9 ? -1 : ans;
    }
};
