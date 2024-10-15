class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int n=s.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                c++;
            }
            else if(s[i]==')'){
                c--;
                if(c<0){
                    ans++;
                    c++;
                }
            }
        }
        if(c!=0)ans+=abs(c);
        return ans;
    }
};