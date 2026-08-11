class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;

        queue<pair<int, pair<int, int>>> q;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        q.push({1, {0, 0}});
        vis[0][0] = 1;

        int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
        int dy[] = {-1, 1, 0, 0, 1, -1, 1, -1};

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int x = it.second.first;
            int y = it.second.second;
            int t = it.first;

            if (x == n - 1 && y == m - 1)
                return t;

            for (int i = 0; i < 8; i++) {

                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] &&
                    grid[nx][ny] == 0) {

                    vis[nx][ny] = 1;

                    q.push({t + 1, {nx, ny}});
                }
            }
        }

        return -1;
    }
};