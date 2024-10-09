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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q; 
        q.push({root, {0, 0}});
        map<int, vector<pair<int, int>>> mp; 

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* x = it.first;
            auto i = it.second;
            int vertical = i.first;
            int depth = i.second;
            mp[vertical].push_back({depth, x->val});
            if (x->left) q.push({x->left, {vertical - 1, depth + 1}});
            if (x->right) q.push({x->right, {vertical + 1, depth + 1}});
        }
        for (auto& it : mp) {
            sort(it.second.begin(), it.second.end());
            vector<int> column;
            for (auto& p : it.second) {
                column.push_back(p.second);
            }
            ans.push_back(column);
        }

        return ans;
    }
};
