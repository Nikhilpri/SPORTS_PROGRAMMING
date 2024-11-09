class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n=nums2.size();
        vector<int>nge(n);
        nge[n-1]=-1;
        stack<int>st;
        st.push(nums2[n-1]);
        unordered_map<int,int>mp;
        mp[nums2[n-1]]=n-1;
        for(int i=n-2;i>=0;i--){
            while(!st.empty()&&nums2[i]>=st.top())st.pop();
            if(st.empty()){
                nge[i]=-1;
            }
            else nge[i]=st.top();

            st.push(nums2[i]);
            mp[nums2[i]]=i;
        }
        for(auto it:nums1){
            ans.push_back(nge[mp[it]]);
        }
        return ans;
    }
};