class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis = grid;
        queue<pair<int, int>> q;
        int cntFreshOranges = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] == 2){
                    q.push({i, j});
                }
                else if(vis[i][j] == 1){
                    cntFreshOranges++;
                }
            }
        }
        if(cntFreshOranges == 0) return 0;
        if(q.empty()) return -1;
        int minutes = -1;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x, y] = q.front();
                q.pop();
                for(auto[dx, dy]:dirs){
                    int i = x+dx;
                    int j = y+dy;
                    if(i<n && i>=0 && j<m && j>=0 && vis[i][j] == 1){
                        vis[i][j] = 2;
                        cntFreshOranges--;
                        q.push({i, j});
                    }
                }
            }
            minutes++;
        }
        if(cntFreshOranges == 0) return minutes;
        return -1;
    }
};