class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1,flag=0;
        for(auto it:nums){
            if(it!=0){
                prod*=it;
            }
            else flag++;
          
        }
        vector<int>ans;
        for(auto it:nums){
            if(it!=0&&flag==0)
            ans.push_back(prod/it);
            else if(it!=0){
                ans.push_back(0);
            }
            else if(flag==1){
                ans.push_back(prod);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};