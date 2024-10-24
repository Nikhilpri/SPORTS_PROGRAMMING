class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m=arr.size();
        int n=arr[0].size();
         vector<vector<int>>dp(m,vector<int>(n,0));
         if(arr[0][0]!=1)
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1)continue;
                if(i>0&&j>0){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
                else if(i>0)dp[i][j]=dp[i-1][j];
                else if(j>0)dp[i][j]=dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};