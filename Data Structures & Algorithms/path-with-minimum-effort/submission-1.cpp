#define P pair<int, pair<int, int>>

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;

        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, {0, 0}});

        while(!pq.empty()){

            auto p = pq.top();

            int dis = p.first;
            int r = p.second.first;
            int c = p.second.second;

            pq.pop();

            if(r==n-1 && c == m-1) return dis;

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int i=0; i<4; i++){

                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow<n && nrow>=0 && ncol<m && ncol>= 0){

                        int curr_diff = abs(heights[r][c] - heights[nrow][ncol]);

                        if(max(curr_diff, dis) < dist[nrow][ncol]){
                            dist[nrow][ncol] = max(curr_diff, dis);
                            pq.push({max(curr_diff, dis), {nrow, ncol}});
                        }
                }
            }
        }

        return -1;
    }
};