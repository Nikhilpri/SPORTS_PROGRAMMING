class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mp,np;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end()&&np.find(t[i])==np.end()){
                mp[s[i]]=t[i];
                np[t[i]]=s[i];
            }
            else{
                if(mp[s[i]]!=t[i]||np[t[i]]!=s[i])return false;
            }
        }
        return true;
    }
};