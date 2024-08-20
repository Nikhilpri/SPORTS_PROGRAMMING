class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        // Initialize variables for tracking the current maximum and minimum products
        double curr_max = nums[0];
        double curr_min = nums[0];
        double ans = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                swap(curr_max, curr_min);
            }

            curr_max = max((double)nums[i], curr_max * nums[i]);
            curr_min = min((double)nums[i], curr_min * nums[i]);

            ans = max(ans, curr_max);
        }

        return (int)ans;
    }
};
