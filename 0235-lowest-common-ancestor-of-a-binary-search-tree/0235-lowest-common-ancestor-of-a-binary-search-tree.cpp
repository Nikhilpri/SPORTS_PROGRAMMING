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
    void solve(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode*& r){
        if(root==NULL)return;
        int x=root->val;
        if((x<=p->val&&x>=q->val)||(x>=p->val&&x<=q->val)){
            r=root;
            return;
        }
        if(x<p->val&&x<q->val){
            solve(root->right,p,q,r);
        }
        else if(x>p->val&&x>q->val){
            solve(root->left,p,q,r);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* r=nullptr;
        solve(root,p,q,r);
        return r;
    }
};