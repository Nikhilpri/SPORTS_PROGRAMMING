class Solution {
public:
    string longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string ans="";
        int i=n,j=m;
        while(i>0&&j>0){
            if(text1[i-1]==text2[j-1]){
                ans+=text1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i][j-1]<dp[i-1][j]){
                    ans+=text2[j-1];
                    j--;
                }
                else{
                    ans+=text1[i-1];
                    i--;
                }
            }
        }
        while(i>0){
           ans+=text1[i-1];
                    i--; 
        }
        while(j>0){
             ans+=text2[j-1];
                    j--;
        }
    reverse(ans.begin(),ans.end());
        return ans;
    }
 
    string shortestCommonSupersequence(string s1, string s) {
         
        return longestCommonSubsequence(s,s1);
    }
};