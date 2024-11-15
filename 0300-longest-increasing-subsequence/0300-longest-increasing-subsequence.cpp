class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
      vector<int>dp(n+1,1);
   int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(arr[i-1]>arr[j-1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }

            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};