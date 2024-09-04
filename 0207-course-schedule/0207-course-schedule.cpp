class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
       vector<int>indeg(n,0);
         vector<vector<int>> adj(n);
    
        for (auto& p : pre) {
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto it:adj[x]){
                indeg[it]--;
                if(indeg[it]==0){
                     q.push(it);
                }
            }

        }
        return ans.size()==n?true:false; 
    }
};