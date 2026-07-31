class Solution {
private:
    void dfs(int r, int c, vector<vector<bool>> &vis, int prev_height, vector<vector<int>>& heights){

        int rows = heights.size();
        int cols = heights[0].size();

        if(r<0 || r>=rows || c<0 || c>=cols || vis[r][c] || heights[r][c] < prev_height){
            return;
        }

        vis[r][c] = true;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            dfs(r + delrow[i], c + delcol[i], vis, heights[r][c], heights);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> alt(rows, vector<bool>(cols, false));

        for(int c=0; c<cols; c++){
            dfs(0, c, pac, heights[0][c], heights);
            dfs(rows-1, c, alt, heights[rows-1][c], heights);
        }

        for(int r=0; r<rows; r++){
            dfs(r, 0, pac, heights[r][0], heights);
            dfs(r, cols-1, alt, heights[r][cols-1], heights);
        }

        vector<vector<int>> result;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(pac[r][c] && alt[r][c]){
                    result.push_back({r,c});
                }
            }
        }

        return result;
    }
};
