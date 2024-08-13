class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum1=0,sum2=0;
        for(auto it:nums){
            if(it<10)sum1+=it;
            else sum2+=it;
        }
        return sum1!=sum2;
    }
};