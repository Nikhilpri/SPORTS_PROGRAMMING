class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<set<int>> leftSums(n + 1), rightSums(n + 1);
        
        // Generate all subset sums for the left half
        for (int i = 0; i < (1 << n); ++i) {
            int sum = 0, bits = __builtin_popcount(i);
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    sum += nums[j];
                }
            }
            leftSums[bits].insert(sum);
        }
        
        // Generate all subset sums for the right half
        for (int i = 0; i < (1 << n); ++i) {
            int sum = 0, bits = __builtin_popcount(i);
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    sum += nums[n + j];
                }
            }
            rightSums[bits].insert(sum);
        }
        
        int minDiff = INT_MAX;
        
        // For each subset size, check the best possible sum in the left and right sets
        for (int k = 0; k <= n; ++k) {
            for (int leftSum : leftSums[k]) {
                int target = totalSum / 2 - leftSum;
                auto it = rightSums[n - k].lower_bound(target);
                
                if (it != rightSums[n - k].end()) {
                    minDiff = min(minDiff, abs(totalSum - 2 * (leftSum + *it)));
                }
                if (it != rightSums[n - k].begin()) {
                    --it;
                    minDiff = min(minDiff, abs(totalSum - 2 * (leftSum + *it)));
                }
            }
        }
        
        return minDiff;
    }
};
