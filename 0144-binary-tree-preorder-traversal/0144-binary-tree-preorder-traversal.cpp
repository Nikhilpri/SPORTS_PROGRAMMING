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
    void pre(TreeNode* root,vector<int>&pretrav){
        if(root==NULL)return;
        pretrav.push_back(root->val);
        if(root->left){
            pre(root->left,pretrav);
        }
        if(root->right){
            pre(root->right,pretrav);
        }
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>pretrav;
        pre(root,pretrav);
        return pretrav;
    }
};