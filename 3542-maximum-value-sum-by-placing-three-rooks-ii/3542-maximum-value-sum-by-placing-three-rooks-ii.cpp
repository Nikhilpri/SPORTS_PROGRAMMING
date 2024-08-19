#include <vector>
#include <array>
#include <algorithm>
#include <climits>

class Solution {
public:
    long long maximumValueSum(std::vector<std::vector<int>>& board) {
        int numRows = board.size();
        int numCols = board[0].size();
        long long maxSum = LLONG_MIN;

        auto topValues = getTopThreeValues(board, numRows, numCols);

        for (int row1 = 0; row1 < numRows; ++row1) {
            for (int row2 = row1 + 1; row2 < numRows; ++row2) {
                for (int row3 = row2 + 1; row3 < numRows; ++row3) {
                    maxSum = std::max(maxSum, calculateMaxSum(topValues[row1], topValues[row2], topValues[row3]));
                }
            }
        }

        return maxSum;
    }

private:
    std::vector<std::array<std::pair<int, int>, 3>> getTopThreeValues(const std::vector<std::vector<int>>& board, int numRows, int numCols) {
        std::vector<std::array<std::pair<int, int>, 3>> topThree(numRows);
        for (int row = 0; row < numRows; ++row) {
            std::vector<std::pair<int, int>> valueColPairs;
            for (int col = 0; col < numCols; ++col) {
                valueColPairs.push_back({board[row][col], col});
            }
            std::sort(valueColPairs.rbegin(), valueColPairs.rend());
            for (int i = 0; i < 3; ++i) {
                topThree[row][i] = valueColPairs[i];
            }
        }
        return topThree;
    }

    long long calculateMaxSum(const std::array<std::pair<int, int>, 3>& topRow1,
                              const std::array<std::pair<int, int>, 3>& topRow2,
                              const std::array<std::pair<int, int>, 3>& topRow3) {
        long long maxSum = LLONG_MIN;

        // Iterate through all possible column combinations
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (topRow1[i].second == topRow2[j].second) continue;
                for (int k = 0; k < 3; ++k) {
                    if (topRow1[i].second == topRow3[k].second || topRow2[j].second == topRow3[k].second) continue;
                    long long currentSum = static_cast<long long>(topRow1[i].first) +
                                           static_cast<long long>(topRow2[j].first) +
                                           static_cast<long long>(topRow3[k].first);
                    maxSum = std::max(maxSum, currentSum);
                }
            }
        }

        return maxSum;
    }
};
