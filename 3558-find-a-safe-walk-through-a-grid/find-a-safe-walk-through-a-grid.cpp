class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> best(m, vector<int>(n, -1));

        queue<tuple<int, int, int>> q;

        int startHealth = health - grid[0][0];
        if (startHealth <= 0)
            return false;

        q.push({0, 0, startHealth});
        best[0][0] = startHealth;

        vector<int> dr = {0, 0, 1, -1};
        vector<int> dc = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [r, c, h] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1)
                return true;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;

                int nh = h - grid[nr][nc];

                if (nh <= 0)
                    continue;

                if (nh <= best[nr][nc])
                    continue;

                best[nr][nc] = nh;
                q.push({nr, nc, nh});
            }
        }

        return false;
    }
};