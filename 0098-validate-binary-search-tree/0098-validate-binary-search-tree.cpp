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
void check(TreeNode* root,vector<int>&inorder){
        if(root->left)check(root->left,inorder);
        inorder.push_back(root->val);
        if(root->right)check(root->right,inorder);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>inorder;
        check(root,inorder);
        int n=inorder.size();
        for(int i=1;i<n;i++){
            if(inorder[i]<=inorder[i-1])return false;
        }
        return true;
    }
};