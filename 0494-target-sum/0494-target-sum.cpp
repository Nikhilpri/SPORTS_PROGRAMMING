class Solution {
public:
int poss(int n,int sum,vector<vector<int>>&dp, vector<int> &arr){
    if(n==0){
        if(sum==0&&arr[n]==0)
        return 2;
        if(sum==0||arr[n]==sum)
        return 1;
        return 0;
    }
    
    if(dp[n][sum]!=-1)
    return dp[n][sum];
    int nott=poss(n-1,sum,dp,arr);
    int take=0;
    if(arr[n]<=sum)take=poss(n-1,sum-arr[n],dp,arr);
 

    return dp[n][sum]=(nott+take)%1000000007;
}
    int findTargetSumWays(vector<int>& arr, int d) {
        int n=arr.size();
        int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if((sum-d)%2||sum<d)return 0;
    sum=(sum-d)/2;
    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
    
    
    return (poss(n-1,sum,dp,arr));
    }
};