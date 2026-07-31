class Solution {
private:
    void bfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& vis, int n, int m){

        vis[r][c] = true;

        queue<pair<int, int>> q;
        q.push({r, c});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){

                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n ,vector<bool>(m, false));

        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    bfs(i, j, grid, vis, n, m);
                }
            }
        }

        return cnt;
    }
};
