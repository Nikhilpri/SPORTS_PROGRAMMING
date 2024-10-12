class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=1e6+2;
        vector<int>arr(n,0);
        int sum=0,ans=1;
        for(auto it:intervals){
            arr[it[0]]++;
            arr[it[1]+1]--;
        }
        for(int i=0;i<n;i++){
            sum+=arr[i];
            ans=max(ans,sum);
        }
        return ans;
    }
};