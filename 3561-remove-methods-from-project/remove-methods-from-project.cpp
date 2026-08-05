class Solution {
public:
    void dfs(int k, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& sus) {
        vis[k] = 1;
        sus[k] = 1;
        for (auto& it : adj[k]) {
            if (!vis[it]) {
                dfs(it, adj, vis, sus);
            }
        }
    }
    bool dfs2(int i, vector<int>& vis2, vector<vector<int>>& adj,
              vector<int>& sus) {
        vis2[i] = 1;
        for (auto& it : adj[i]) {
            if (!vis2[it]) {
                if (sus[it])
                    return true;
                else {
                    if (dfs2(it, vis2, adj, sus))
                        return true;
                }
            }
        }
        return false;
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto& it : invocations) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        vector<int> vis(n, 0);
        vector<int> sus(n, 0);
        dfs(k, adj, vis, sus);

        vector<int> vis2(n, 0);
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (!vis2[i] && !sus[i]) {
                if (dfs2(i, vis2, adj, sus)) {
                    ok = true;
                }
            }
        }
        vector<int> res;
        if (ok) {
            for (int i = 0; i < n; i++) {
                res.push_back(i);
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (sus[i] == 0) {
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};