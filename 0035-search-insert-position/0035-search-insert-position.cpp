class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid;
        int i=-1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<target){
                i=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return i+1;
    }
};