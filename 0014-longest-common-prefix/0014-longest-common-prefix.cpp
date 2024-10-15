class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        int n=strs.size();
        for(int i=1;i<n;i++){
            string comm="";
            string s1=strs[i];
            int m=min(ans.size(),s1.size());
            int j=0;
            while(j<m&&s1[j]==ans[j]){
                comm+=s1[j];
                j++;
            }
            ans=comm;
        }
        return ans;
    }
};