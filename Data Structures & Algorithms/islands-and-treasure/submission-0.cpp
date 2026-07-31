class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){

            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

             if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol] == 2147483647){
                grid[nrow][ncol] = grid[r][c] + 1;
                q.push({nrow, ncol});
            }

        }
    }

    return;
}
};
