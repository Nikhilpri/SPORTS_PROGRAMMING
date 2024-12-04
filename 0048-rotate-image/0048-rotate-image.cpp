class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=arr[i][j]+1500;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=(arr[n-j-1][i]%2000)*2000+arr[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=arr[i][j]/2000-1500;
            }
            cout<<endl;
        }
        
    }
};