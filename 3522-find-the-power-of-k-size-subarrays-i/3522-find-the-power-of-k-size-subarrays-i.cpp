class Solution {
public:
    vector<int> resultsArray(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result;

        for (int i = 0; i <= n - k; i++) {
            bool isConsecutive = true;
            int maxElement = arr[i];
            
            for (int j = i + 1; j < i + k; j++) {
                if (arr[j] != arr[j - 1] + 1) {
                    isConsecutive = false;
                    break;
                }
                maxElement = max(maxElement, arr[j]);
            }

            if (isConsecutive) {
                result.push_back(maxElement);
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }
};