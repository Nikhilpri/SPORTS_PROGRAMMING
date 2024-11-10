class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, n);
        vector<int> pse(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] <= arr[st.top()]) st.pop();
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] < arr[st.top()]) st.pop();
            if (!st.empty()) nse[i] = st.top();
            st.push(i);
        }

        long long sum = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            sum = (sum + left * right % mod * arr[i] % mod) % mod;
        }
        
        return sum;
    }
};
