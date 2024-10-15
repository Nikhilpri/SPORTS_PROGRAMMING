class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        int n=s.size();
        vector<int>arr(26,0);
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        for(auto it:s){
            if(arr[it-'a']!=0)return false;
        }
        return true;
    }
};