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
    void check(TreeNode* root,map<TreeNode*,TreeNode*>&par){
        if(root->left){
            par[root->left]=root;
            check(root->left,par);
        }
        if(root->right){
            par[root->right]=root;
            check(root->right,par);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>par;
        check(root,par);
        queue<pair<TreeNode*,int>>q;
        q.push({target,0});
        vector<int>ans;
        map<TreeNode*,bool>vis;
        par[root]=NULL;
        vis[target]=true;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode* x=it.first;
            int dis=it.second;
            if(dis>k)break;
            if(dis==k){
                ans.push_back(x->val);
            }
            if(x->left&&vis[x->left]==false){
                q.push({x->left,dis+1});
                vis[x->left]=true;
            }
            if(x->right&&vis[x->right]==false){
                q.push({x->right,dis+1});
                vis[x->right]=true;
            }
            if(par[x]&&vis[par[x]]==false){
                q.push({par[x],dis+1});
                vis[par[x]]=true;
            }
        }
        return ans;
    }
};