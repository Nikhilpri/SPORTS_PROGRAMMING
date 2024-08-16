class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;
        
        sort(nums.begin(), nums.end());
        
        int min_diff = min({
            nums[n-1] - nums[3],   // Remove 3 smallest
            nums[n-4] - nums[0],   // Remove 3 largest
            nums[n-2] - nums[2],   // Remove 2 smallest and 1 largest
            nums[n-3] - nums[1]    // Remove 1 smallest and 2 largest
        });
        
        return min_diff;
    }
};