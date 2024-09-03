class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        
         vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        vector<pair<int,int>>dirs={{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>>ans(n,vector<int>(m,0));
        while(!q.empty()){
            auto f=q.front();
            int i=f.first.first;
            int j=f.first.second;
            int dis=f.second;
            q.pop();
            for(auto it:dirs){
                int x=it.first+i;
                int y=it.second+j;
                if(x<n&&y<m&&x>=0&&y>=0){
                    if(vis[x][y]==false&&mat[x][y]==1){
                        ans[x][y]=dis+1;
                        q.push({{x,y},dis+1});
                        vis[x][y]=true;
                    }
                }
            }
        }
        return ans;
    }
};