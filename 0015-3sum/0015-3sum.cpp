#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<pair<int, int>>> sum2; 
        set<vector<int>> ans; 
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                sum2[nums[i] + nums[j]].emplace_back(i, j);
            }
        }

        for (int i = 0; i < n; i++) {
            int target = -nums[i];
            if (sum2.find(target) != sum2.end()) {
                for (auto &p : sum2[target]) {
                    if (p.first != i && p.second != i) {
                        vector<int> triplet = {nums[i], nums[p.first], nums[p.second]};
                        sort(triplet.begin(), triplet.end()); 
                        ans.insert(triplet); 
                    }
                }
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
