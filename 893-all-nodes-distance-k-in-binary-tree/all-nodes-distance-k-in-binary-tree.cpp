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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        unordered_map<TreeNode*, int> vis;
        q.push(target);
        vis[target] = 1;
        int dis = 0;
        while (!q.empty()) {
            int siz = q.size();
            if (dis == k) {
                while (!q.empty()) {
                    TreeNode* node = q.front();
                    q.pop();
                    ans.push_back(node->val);
                }
                return ans;
            }

            for (int i = 0; i < siz; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !vis[node->left]) {
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if (node->right && !vis[node->right]) {
                    vis[node->right] = 1;
                    q.push(node->right);
                }
                if (parent[node] && !vis[parent[node]]) {
                    vis[parent[node]] = 1;
                    q.push(parent[node]);
                }
            }
            dis++;
        }
        return ans;
    }
};