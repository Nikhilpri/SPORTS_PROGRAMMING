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
    void check(TreeNode* root,map<int,bool>&mp){
        mp[root->val]=true;
        if(root->left)check(root->left,mp);
        if(root->right)check(root->right,mp);
    }
    bool findTarget(TreeNode* root, int k) {
        map<int,bool>mp;
        check(root,mp);
        for(auto it:mp){
            if(k-it.first==it.first)continue;
            if(mp.find(k-it.first)!=mp.end())return true;
        }
        return false;
    }
};