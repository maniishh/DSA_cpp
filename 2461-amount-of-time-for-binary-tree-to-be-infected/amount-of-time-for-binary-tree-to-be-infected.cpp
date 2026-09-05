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
public:
    TreeNode* f(TreeNode* root, map<TreeNode*, TreeNode*>& mp, int st) {
        TreeNode* res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->val == st)
                res = node;
            if (node->left) {
                mp[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                mp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    int solve(map<TreeNode*, TreeNode*>& mp, TreeNode* k) {
        map<TreeNode*, int> vis;
        queue<TreeNode*> q;
        q.push(k);
        vis[k] = 1;
        int cnt = 0;
        while (!q.empty()) {
            int siz = q.size();
            int fl = 0;
            for (int i = 0; i < siz; i++) {
                auto node = q.front();
                q.pop();
                if (node->left && !vis[node->left]) {
                    fl = 1;
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if (node->right && !vis[node->right]) {
                    fl = 1;
                    vis[node->right] = 1;
                    q.push(node->right);
                }
                if (mp[node] && !vis[mp[node]]) {
                    fl = 1;
                    vis[mp[node]] = 1;
                    q.push(mp[node]);
                }
            }
            if (fl)
                cnt++;
        }
        return cnt;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> mp;
        TreeNode* target = f(root, mp, start);
        int maxi = solve(mp, target);
        return maxi;
    }
};