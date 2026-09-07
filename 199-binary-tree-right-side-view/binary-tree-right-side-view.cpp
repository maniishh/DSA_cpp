/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void solve(vector<int>& res, TreeNode* root, int level) {
        if (!root)
            return;
        if (res.size() == level) {
            res.push_back(root->val);
        }
        solve(res, root->right, level + 1);
        solve(res, root->left, level + 1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        solve(res, root, 0);
        return res;
    }
};