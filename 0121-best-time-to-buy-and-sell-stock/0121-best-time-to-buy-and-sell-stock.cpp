class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int right[n];
        right[n-1]=0;
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],prices[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int prof=right[i]-prices[i];
            ans=max(ans,prof);
        }
        return ans;
    }
};