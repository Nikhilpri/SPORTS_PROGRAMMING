class Solution {
public:
void dfs(int v, vector<vector<int>>&adj,vector<bool>&vis,int i){
      vis[i]=true;
      for(auto it:adj[i]){
          if(vis[it]==false){
              dfs(v,adj,vis,it);
          }
      }
  }
    int findCircleNum(vector<vector<int>>& arr) {
        int v=arr.size();
          vector<bool>vis(v,false);
          vector<vector<int>>adj(v);
          for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(arr[i][j]==1){
                    adj[i].push_back(j);
                }
            }
          }
        int ans=0;
        for(int i=0;i<v;i++){
            if(vis[i]==false){
                dfs(v,adj,vis,i);
                ans++;
            }
        }
        return ans;
    }
};