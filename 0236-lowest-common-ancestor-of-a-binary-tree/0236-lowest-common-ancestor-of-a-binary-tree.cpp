/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent(TreeNode* root,map<TreeNode*,TreeNode*>&mp){
        if(root->left){
            mp[root->left]=root;
            parent(root->left,mp);
        }
        if(root->right){
            mp[root->right]=root;
            parent(root->right,mp);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*,TreeNode*>mp;
        mp[root]=NULL;
        parent(root,mp);
        vector<TreeNode*>pd,qd;
        TreeNode* par=mp[p];
        pd.push_back(p);
        while(par!=NULL){
            pd.push_back(par);
            par=mp[par];
        }
        par=mp[q];
         qd.push_back(q);
        while(par!=NULL){
            qd.push_back(par);
            par=mp[par];
        }
        reverse(pd.begin(),pd.end());
        reverse(qd.begin(),qd.end());
        int i=0;
        while (i < pd.size() && i < qd.size() && pd[i] == qd[i]) {
            i++;
        }
        return pd[i-1];
    }
};