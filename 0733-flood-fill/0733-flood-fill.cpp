class Solution {
public:
    void dfs(vector<vector<int>>& image,vector<vector<bool>>&vis,int i,int j, int n, int m,int color,int old){
        if(image[i][j]!=old)return;
        vis[i][j]=true;
        image[i][j]=color;
        vector<pair<int,int>>dirs={{-1,0},{1,0},{0,-1},{0,1}};
        for(auto it:dirs){
            int x=i+it.first;
            int y=j+it.second;
            if(x>=0&&y>=0&&x<n&&y<m&&vis[x][y]==false){
                dfs(image,vis,x,y,n,m,color,old);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int old=image[sr][sc];
        dfs(image,vis,sr,sc,n,m,color,old);
        return image;
    }
};