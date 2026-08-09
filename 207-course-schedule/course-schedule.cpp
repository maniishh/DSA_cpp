class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        vector<int> indegree(v, 0);
        vector<vector<int>> adj(v);
        queue<int> q;
        for (auto& p : prerequisites) {
            int u = p[1];
            int v = p[0];
            adj[u].push_back(v);
        }
        for (int i = 0; i < v; i++) {
            for (auto& it : adj[i]) {
                indegree[it]++;
            }
        }
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> res;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);

            for (auto& it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return numCourses == res.size();
    }
};