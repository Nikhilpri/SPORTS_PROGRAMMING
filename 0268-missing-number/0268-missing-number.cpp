class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int prod=0;
        int n=nums.size();
        for(int i=0;i<=n;i++){
            prod^=i;
        }
        for(auto it:nums){
            prod^=it;
                    }
                    return prod;
    }
};