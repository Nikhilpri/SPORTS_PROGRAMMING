class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<bool>&vis,vector<bool>&sol,int i){
        vis[i]=true;
        sol[i]=true;
        for(auto it:graph[i]){
            if(vis[it]==false){
                if(dfs(graph,vis,sol,it))return true;
            }
            else if(sol[it]==true)return true;
        }
        sol[i]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>vis(n,false);
        vector<bool>sol(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]==false){
            dfs(graph,vis,sol,i);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!sol[i])ans.push_back(i);
        }
        return ans;

    }
};