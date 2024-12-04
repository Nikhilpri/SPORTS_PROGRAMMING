class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        
        int n=arr.size();
        bool flag=1;
        for(int i=0;i<n-1;i++){
            if(arr[i]>=arr[i+1])continue;
            flag=0;
        }
        if(flag){
            reverse(arr.begin(),arr.end());
            return;
        }
        for(int i=n-1;i>0;i--){
            if(arr[i-1]>=arr[i])continue;
            int ind=i,mini=arr[i];
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i-1]){
                    mini=arr[j];
                    ind=j;
                }
            }
            swap(arr[i-1],arr[ind]);  
            reverse(arr.begin()+i,arr.end());
            break;
        }
    }
};