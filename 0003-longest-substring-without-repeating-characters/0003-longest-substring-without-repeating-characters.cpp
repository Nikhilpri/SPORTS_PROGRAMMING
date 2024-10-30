class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        set<char>st;
        int ans=0;
        while(j<n){
            while(j<n&&st.find(s[j])==st.end()){
                st.insert(s[j]);
                j++;
            }
            ans=max(ans,j-i);
            while(i<=j&&st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};