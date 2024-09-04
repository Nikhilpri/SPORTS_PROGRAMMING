class Solution {
public:
    int numEnclaves(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1)) {
                    if (mat[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = true;
                    }
                }
            }
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto f = q.front();
            int i = f.first;
            int j = f.second;
            q.pop();
            for (auto it : dirs) {
                int x = it.first + i;
                int y = it.second + j;
                if (x < n && y < m && x >= 0 && y >= 0) {
                    if (vis[x][y] == false && mat[x][y] == 1) {
                        q.push({x, y});
                        vis[x][y] = true;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == false&&mat[i][j] == 1) {
                    ans++;
                } 
            }
        }
        return ans;
    }
};