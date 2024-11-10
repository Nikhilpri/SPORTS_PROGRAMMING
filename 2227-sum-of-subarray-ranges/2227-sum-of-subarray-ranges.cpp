class Solution {
public:
    vector<int> prevSmaller(vector<int>& nums) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++) {
            int element = nums[i];
            while (!st.empty() && st.top() != -1 && nums[st.top()] >= element)
                st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nextSmaller(vector<int>& nums) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(nums.size(), -1);
        for (int i = nums.size() - 1; i >= 0; i--) {
            int element = nums[i];
            while (!st.empty() && st.top() != -1 && nums[st.top()] > element)
                st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMins(vector<int>& nums) {
        vector<int> prev = prevSmaller(nums);
        vector<int> next = nextSmaller(nums);
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int previ = prev[i];
            int nexti = next[i] == -1 ? nums.size() : next[i];
            int left = i - previ;
            int right = nexti - i;
            long long currSize = left * right;
            long long val = nums[i] * currSize;
            sum += val;
        }
        return sum;
    }
    vector<int> prevGreater(vector<int>& nums) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++) {
            int element = nums[i];
            while (!st.empty() && st.top() != -1 && nums[st.top()] <= element)
                st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nextGreater(vector<int>& nums) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(nums.size(), -1);
        for (int i = nums.size() - 1; i >= 0; i--) {
            int element = nums[i];
            while (!st.empty() && st.top() != -1 && nums[st.top()] < element)
                st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMaxs(vector<int>& nums) {
        vector<int> prev = prevGreater(nums);
        vector<int> next = nextGreater(nums);
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int previ = prev[i];
            int nexti = next[i] == -1 ? nums.size() : next[i];
            int left = i - previ;
            int right = nexti - i;
            long long currSize = left * right;
            long long val = nums[i] * currSize;
            sum += val;
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};