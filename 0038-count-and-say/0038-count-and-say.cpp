class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 1; i < n; i++) {
            string check = "";
            int l = 1;
            int m = ans.length();
            char last = ans[0];
            for (int j = 1; j < m; j++) {
                if (ans[j] == last)
                    l++;
                else {
                    check += to_string(l);
                    check += last;
                    l = 1;
                    last = ans[j];
                }
            }
            check += to_string(l);
            check += last;
            ans = check;
        }
        return ans;
    }
};