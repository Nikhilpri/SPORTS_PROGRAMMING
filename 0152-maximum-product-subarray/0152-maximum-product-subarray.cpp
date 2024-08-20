class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<vector<double>>dp(n,vector<double>(2,0));
        dp[0][0]=1;
        dp[0][1]=nums[0];
        double ans=nums[0];
        for(int i=1;i<n;i++){
            dp[i][0]=min({(double)nums[i],dp[i-1][0]*nums[i],dp[i-1][1]*nums[i]});
            dp[i][1]=max({(double)nums[i],dp[i-1][0]*nums[i],dp[i-1][1]*nums[i]});
            ans=max(ans,dp[i][1]);
        }
        return ans;
    }
};