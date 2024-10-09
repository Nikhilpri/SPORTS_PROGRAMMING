/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* r,TreeNode* s){
        if(r==NULL&&s==NULL)return true;
        if(r==NULL||s==NULL||r->val!=s->val)return false;
        return check(r->left,s->right)&&check(r->right,s->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }
};