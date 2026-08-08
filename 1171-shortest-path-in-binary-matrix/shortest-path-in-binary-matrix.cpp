class Solution {
public:
int ShortestPath(vector<vector<int>> &grid, pair<int,int> source, pair<int,int> destination){
    queue<pair<int,pair<int,int>>> q;
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[source.first][source.second] = 1; 
    q.push({1,{source.first, source.second}}); 

    int dr[] = {-1,-1,-1,0,1,1,1,0};
    int dc[] = {-1,0,1,1,1,0,-1,-1};

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;

        for(int i = 0; i < 8; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0 && dis + 1 < dist[nr][nc]){
                dist[nr][nc] = dis + 1;
                if(nr == destination.first && nc == destination.second){
                    return dis + 1;
                }
                q.push({dis + 1, {nr, nc}});
            }
        }
    }

    return -1;  
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
    if(n == 1 && m == 1 && grid[0][0] == 0) return 1; 

    return ShortestPath(grid, {0,0}, {n-1,m-1});
}

};