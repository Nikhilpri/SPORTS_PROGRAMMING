class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        vector<int>nge(n,-1);
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty()&&nums[i%n]>=nums[st.top()])st.pop();
            if(i<n&&!st.empty()){
                nge[i]=nums[st.top()];
            }

            st.push(i%n);
        }
        return nge;
    }
};