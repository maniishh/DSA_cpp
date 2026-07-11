class Solution {
public:
    vector<vector<int>> graph;
    vector<int> vis;
    int nodes;
    int degreeSum;

    void dfs(int u) {
        vis[u] = 1;
        nodes++;
        degreeSum += graph[u].size();

        for (int v : graph[u]) {
            if (!vis[v])
                dfs(v);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        vis.assign(n, 0);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                nodes = 0;
                degreeSum = 0;

                dfs(i);

                int edgeCount = degreeSum / 2;
                if (edgeCount == nodes * (nodes - 1) / 2)
                    ans++;
            }
        }

        return ans;
    }
};