class Solution {
public:
    void f(int x, int y, vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            matrix[i][y] = 0;
        }
        for (int j = 0; j < m; j++) {
            matrix[x][j] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int, int>> z;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    z.push_back({i, j});
                }
            }
        }
        for (auto it : z) {
            int x = it.first;
            int y = it.second;
            f(x, y, matrix);
        }
    }
};