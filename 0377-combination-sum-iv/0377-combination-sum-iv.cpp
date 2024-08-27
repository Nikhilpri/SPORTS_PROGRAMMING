class Solution {
public:
    int count(vector<int>& arr, int tar, int i, vector<vector<int>>& dp) {
        if (tar < 0) return 0;
        
        if (tar == 0) return 1;
        
        
        if (dp[i][tar] != -1) return dp[i][tar];
        
        int t = 0;
        for(int j=0;j<arr.size();j++){
            if (arr[j] <= tar) t +=count(arr, tar - arr[j], j , dp);
        }
        
        
        return dp[i][tar] = t ;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target + 1, -1));
         count(nums, target, n - 1, dp);
         return dp[n-1][target];
    }
};
