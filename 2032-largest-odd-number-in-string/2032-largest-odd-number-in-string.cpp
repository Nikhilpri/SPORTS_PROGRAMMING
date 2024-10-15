class Solution {
public:
    string largestOddNumber(string num) {
        string ans;
        int n=num.size();
        int f=0,i=n-1;
     while(i>=0&&(num[i]-'0')%2==0){
                i--;
            }
        while(i>=0){
            ans+=num[i];
            i--;
        }
       
        reverse(ans.begin(),ans.end());
        return ans;
    }
};