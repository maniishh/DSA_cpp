class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<tuple<int, int, int, int>> q;
        for (auto& s : sources) {
            int r = s[0], c = s[1], color = s[2];
            q.push({r, c, color, 0});
            grid[r][c] = color;
            dist[r][c] = 0;
        }
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [r, c, color, d] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                    continue;

                if (dist[nr][nc] > d + 1) {
                    dist[nr][nc] = d + 1;
                    grid[nr][nc] = color;
                    q.push({nr, nc, color, d + 1});
                } else if (dist[nr][nc] == d + 1 &&grid[nr][nc]<color) {
                    grid[nr][nc] = color;
                    q.push({nr,nc,color,d+1});
                    
                }
            }
        }
        return grid;
    }
};