class Solution {
public:
    int helper(string text1, string text2,int i,int j,vector<vector<int>>&dp) {
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(text1[i]==text2[j]){
            return dp[i][j]=1+helper(text1,text2,i-1,j-1,dp);
        }
        else{
            int x=helper(text1,text2,i,j-1,dp);
            int y=helper(text1,text2,i-1,j,dp);
            return dp[i][j]=max(x,y);
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};