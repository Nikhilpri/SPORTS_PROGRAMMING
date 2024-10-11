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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else{
            if(root->left==NULL&&root->right==NULL){
                return NULL;
            }
            else if(root->left==NULL||root->right==NULL){
                return root->right?root->right:root->left;
            }
            else{
                TreeNode* temp=root->left;
                while(temp->right!=NULL){
                    temp=temp->right;
                }
                temp->right=root->right;
                return root->left;
            }
        }
        return root;
    }
};