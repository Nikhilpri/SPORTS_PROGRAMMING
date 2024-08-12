class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int>st;
        for(int i=0;i<n;i++){
            st.insert(i);
        }

        vector<int> ans;
        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];
            auto start=st.lower_bound(u+1);
            auto end=st.upper_bound(v-1);
            st.erase(start,end);
             ans.push_back(st.size()-1);
            
        }
        return ans;
    }
};