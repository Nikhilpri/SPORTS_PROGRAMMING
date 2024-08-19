class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        // Outer map keys are players, inner map keys are events or categories, values are counts.
        map<int, map<int, int>> mp;

        // Populate the map with pick counts
        for (auto& it : pick) {
            int x = it[0]; // player
            int y = it[1]; // event/category
            mp[x][y]++;
        }

        int ans = 0;
        // Iterate over each player
        for (int i = 0; i < n; i++) {
            bool won = false;
            for (auto& it : mp[i]) {
                if (it.second >= i + 1) { // Condition to check if this is a "winning" condition
                    won = true;
                    break;
                }
            }
            if (won) {
                ans++;
            }
        }
        return ans;
    }
};
