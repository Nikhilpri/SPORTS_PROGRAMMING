class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        int i=0,j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans=0;
        while(i<n&&j<m){
            if(s[j]>=g[i]){
                i++;
                ans++;
            }
            j++;
        }
        return ans;
    }
};