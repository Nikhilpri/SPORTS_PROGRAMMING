class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int col, int i, vector<int>& color) {
        color[i] = col;
        for (auto it : graph[i]) {
            if (color[it] == -1) {
                if (dfs(graph, !col, it, color) == false)
                    return false;
            } else if (color[it] == col)
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i=0;i<n;i++) {
            if (color[i] == -1) {
                if (dfs(graph,0, i, color) == false)
                    return false;
            } 
        }
        return true;
    }
};