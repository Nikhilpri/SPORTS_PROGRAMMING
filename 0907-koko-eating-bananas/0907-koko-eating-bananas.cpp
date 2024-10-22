class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1,r=1,mid;
        for(auto it:piles){
            r=max(r,it);
        }
        int ans=0;
        while(l<=r){
            mid=l+(r-l)/2;
            long long int sum=0;
            for(auto it:piles){
                sum+=it/mid;
                if(it%mid!=0)sum++;
            }
            if(sum<=h){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};