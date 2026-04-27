class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (vis[i][j])
                    continue;

                queue<pair<pair<int, int>, pair<int, int>>> q;
                q.push({{i, j}, {-1, -1}});
                vis[i][j] = 1;

                while (!q.empty()) {
                    auto it = q.front();
                    q.pop();

                    int x = it.first.first;
                    int y = it.first.second;
                    int px = it.second.first;
                    int py = it.second.second;

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                            grid[nx][ny] == grid[x][y]) {

                            if (!vis[nx][ny]) {
                                vis[nx][ny] = 1;
                                q.push({{nx, ny}, {x, y}});
                            } else if (nx != px || ny != py) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};