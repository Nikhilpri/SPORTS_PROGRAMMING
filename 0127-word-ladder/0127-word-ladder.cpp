class Solution {
public:
    int ladderLength(string beg, string end, vector<string>& wordList) {
        int n=beg.size();
        int m=end.size();
        if(m!=n)return 0;
        set<string>st;
        for(auto it:wordList){
            st.insert(it);
        }
        st.erase(beg);
        if(st.find(end)==st.end())return 0;
        queue<pair<string,int>>q;
        q.push({beg,1});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string x=it.first;
            int step=it.second;
            
            if(x==end)return step;
            for(int i=0;i<x.size();i++){
                for(char j='a';j<='z';j++){
                    char y=x[i];
                    x[i]=j;
                    if(st.find(x)!=st.end()){
                        q.push({x,step+1});
                        st.erase(x);
                    }
                    x[i]=y;
                }
            }
        }
        return 0;
    }
};