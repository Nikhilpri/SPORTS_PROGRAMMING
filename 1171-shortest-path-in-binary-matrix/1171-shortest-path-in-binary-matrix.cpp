class Solution {
public:
    bool check(int i, int j, int n) {
        return i < n && j < n && i >= 0 && j >= 0;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
            return -1;  
        }
        int ans = 1e9, len = 1;
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
    int y=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int x=it.first.first;
            int y=it.first.second;
            int dis=it.second;
            if(x==n-1&&y==n-1){
                ans=min(ans,dis);
                break;
            }
            
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nx = x + i;
                    int ny = y + j;
                    if(i==j&&i==0)continue;
                    if(check(nx,ny,n)&&vis[nx][ny]==false&&grid[nx][ny]==0){
                        q.push({{nx,ny},dis+1});
                        vis[nx][ny]=true;
                    }
                }
            }
        }
        
        if (ans == 1e9) return -1; 
        return ans;
    }
};
