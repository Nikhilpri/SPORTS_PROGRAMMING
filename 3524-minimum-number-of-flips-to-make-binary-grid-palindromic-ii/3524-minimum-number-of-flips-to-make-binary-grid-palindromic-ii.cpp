class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        int tot=0;
        for(int i=0;i<(m)/2;i++){
            for(int j=0;j<(n)/2;j++){
                int a=i,b=j,c=n-j-1,d=m-i-1;
                int sum=grid[a][b]+grid[d][b]+grid[a][c]+grid[d][c];
                int y=1;
               
                if(sum<2){
                    y=0;
                    ans+=(sum);
                }
                else{
                    ans+=(4-sum);
                     tot+=4;
                }
            
            }
        }
        if(n%2==0 && m%2==0) return ans;
        int change=0;
        if(m%2==1){
            for(int j=0;j<n/2;j++){
                
                if(grid[m/2][j]!=grid[m/2][n-j-1]){
                    change++;
                    ans++;
                }
                else{
                    if(grid[m/2][j]==1){
                        tot++;
                    }
                }
            }
        }
         if(n%2==1){
            for(int i=0;i<m/2;i++){
                if(grid[i][n/2]!=grid[m-i-1][n/2]){
                    ans++;
                    change++;
                }
                 else{
                    if(grid[i][n/2]==1){
                        tot++;
                    }
                }
            }
        }
        
         if(n%2==1 && m%2==1 && grid[m/2][n/2]==1) ans++;

        if(tot%2==1){
            if(change==0) ans+=2;
        }
        return ans;
    }
};