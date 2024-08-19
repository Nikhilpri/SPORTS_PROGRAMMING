class Solution {
public:
    vector<int> resultsArray(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result;
        int validPairs = 0;
        for (int i = 1; i < k; i++) {
            if (arr[i] == arr[i - 1] + 1) {
                validPairs++;
            }
        }
        if (validPairs == k - 1) {
            result.push_back(arr[k - 1]);
        } else {
            result.push_back(-1);
        }
        for (int i = k; i < n; i++) {
            if (arr[i - k + 1] == arr[i - k] + 1) {
                validPairs--;
            }

            if (arr[i] == arr[i - 1] + 1) {
                validPairs++;
            }

            if (validPairs == k - 1) {
                result.push_back(arr[i]);
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }
};