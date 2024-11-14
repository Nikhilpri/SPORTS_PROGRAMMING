class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=0;
       priority_queue<pair<int,int>> q;
        int currmax = INT_MIN;
        vector<int> ans;
        
        while(j<nums.size())
        {
             q.push({nums[j],j});
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k && !q.empty())
             {
                while(!q.empty() && j-q.top().second+1>k) q.pop();
                ans.push_back(q.top().first);
                j++;
               i++;
             }


        }
     return ans;
        
    }
};