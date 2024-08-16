class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        unordered_map<char, int> left, right;
        vector<int> leftUnique(n), rightUnique(n);
        
        for (int i = 0; i < n; ++i) {
            left[s[i]]++;
            leftUnique[i] = left.size();
        }
        
        for (int i = n - 1; i >= 0; --i) {
            right[s[i]]++;
            rightUnique[i] = right.size();
        }
        
        int count = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (leftUnique[i] == rightUnique[i + 1]) {
                count++;
            }
        }
        
        return count;
    }
};