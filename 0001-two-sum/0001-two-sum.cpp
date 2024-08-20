class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int check=0;
        int i=0,j=0;
        for(auto it:nums){
            if(mp[target-it]>0){
                check=it;
                 if (check == target - check && mp[check] < 2) continue;
                break;
            }
        }
        for(int k=0;k<nums.size();k++){
            if(nums[k]==check){
                i=k;
                break;
            }
        }
        for(int k=0;k<nums.size();k++){
            if(nums[k]==(target-check)&&(k!=i)){
                j=k;
                break;
            }
        }

        
        vector<int>ans={i,j};
        return ans;
    }
};