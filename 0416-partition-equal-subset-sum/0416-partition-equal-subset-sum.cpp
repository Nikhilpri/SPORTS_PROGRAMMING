class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        if(sum%2)return 0;
        else sum/=2;
        
        dp[0][nums[0]]=1;
        dp[0][0]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if(j-nums[i]>=0){
                    if(dp[i-1][j-nums[i]]==1){
                        dp[i][j]=1;
                    }
                }
            }

        }
        return dp[n-1][sum];
    }
};