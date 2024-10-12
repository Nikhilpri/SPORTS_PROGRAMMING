class Solution {
public:
    class Node{
        public:
        Node* links[2]={nullptr};
        bool endofnum=false;
        bool iscon(int i){
            return links[i]!=nullptr;
        }
        Node* get(int i){
            return links[i];
        }
        void put(int i,Node* newnode){
            links[i]=newnode;
        }
    };
    class Trie{
        public:
        Node* root;
        Trie(){
            root=new Node();
        }
        void insert(int number){
            bitset<32>bt=number;
            Node* node=root;
            for(int i=31;i>=0;i--){
                if(node->iscon(bt[i])==false){
                    node->put(bt[i],new Node());
                }
                node=node->get(bt[i]);
            }
            node->endofnum=true;
        }
         int maxi(int num) {
            bitset<32> bt = num;
            int ans = 0;
            Node* node = root;

            for (int i = 31; i >= 0; i--) {
                int opposite = !bt[i]; 
                if (node->iscon(opposite)) {
                    ans |= (1 << i);    
                    node = node->get(opposite); 
                } else if (node->iscon(bt[i])) {
                    node = node->get(bt[i]); 
                } else {
                    ans=0;
                    break;
                }
               
            }
            return ans;
        }
    };
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto it:nums){
            trie.insert(it);
        }
        int ans=0;
        for(auto it:nums){
            ans=max(ans,trie.maxi(it));
        }
        return ans;
    }
};