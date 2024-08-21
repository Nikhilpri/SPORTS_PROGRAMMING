class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>an;
        for(int i=0; i<=n;i++){
            an.push_back(__builtin_popcount(i));
        }
        return an;
    }
};