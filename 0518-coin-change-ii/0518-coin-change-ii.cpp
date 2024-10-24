class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=amount;j++){
                int nt=dp[i-1][j];
                int t=0;
                if(coins[i-1]<=j){
                    t=dp[i][j-coins[i-1]];
                }
                dp[i][j]=t+nt;
            }
        }
        return dp[n][amount];
    }
};