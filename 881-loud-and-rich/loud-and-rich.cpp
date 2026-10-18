
class Solution {
public:
    int dfs(int p, vector<int>& q, vector<int>& ans,
            vector<vector<int>>& adj) {

        if (ans[p] != -1)
            return ans[p];

        ans[p] = p;

        for (auto it : adj[p]) {
            int cnd = dfs(it, q, ans, adj);

            if (q[cnd] < q[ans[p]]) {
                ans[p] = cnd;
            }
        }

        return ans[p];
    }

    vector<int> loudAndRich(vector<vector<int>>& richer,
                            vector<int>& quiet) {
        int n = quiet.size();

        vector<int> ans(n, -1);
        vector<vector<int>> adj(n);

        for (auto it : richer) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            dfs(i, quiet, ans, adj);
        }

        return ans;
    }
};
