class Solution {
public:
    long long maximumValueSum(std::vector<std::vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        long long maxSum = LLONG_MIN;

        // Precompute the top 3 values and their column indices for each row
        std::vector<std::vector<std::pair<int, int>>> top3(m); // stores (value, column index)

        for (int i = 0; i < m; ++i) {
            std::vector<std::pair<int, int>> rowValues;
            for (int j = 0; j < n; ++j) {
                rowValues.push_back({board[i][j], j});
            }
            // Sort row values in descending order to get the top 3
            std::sort(rowValues.rbegin(), rowValues.rend());
            top3[i] = {rowValues[0], rowValues[1], rowValues[2]};
        }

        // Iterate through all combinations of three different rows
        for (int r1 = 0; r1 < m; ++r1) {
            for (int r2 = r1 + 1; r2 < m; ++r2) {
                for (int r3 = r2 + 1; r3 < m; ++r3) {
                    // For these rows, try to pick the best combination of columns
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            if (top3[r1][i].second == top3[r2][j].second) continue;
                            for (int k = 0; k < 3; ++k) {
                                if (top3[r1][i].second == top3[r3][k].second || top3[r2][j].second == top3[r3][k].second) continue;

                                // Valid combination of columns, calculate the sum
                                long long currentSum = static_cast<long long>(top3[r1][i].first) +
                                                       static_cast<long long>(top3[r2][j].first) +
                                                       static_cast<long long>(top3[r3][k].first);
                                maxSum = std::max(maxSum, currentSum);
                            }
                        }
                    }
                }
            }
        }

        return maxSum;
    }
};