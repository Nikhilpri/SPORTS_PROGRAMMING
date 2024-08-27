class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;  // No valid encoding for strings starting with '0'

        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // Base case: empty string
        dp[1] = (s[0] != '0') ? 1 : 0;  // Single character decode
        
        for (int i = 2; i <= n; i++) {
            // Check the single digit possibility
            if (s[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }

            // Check the two-digit possibility
            int twoDigit = stoi(s.substr(i - 2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};
