class Solution {
    private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
        vis[node] = true;

        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
           
           vector<vector<int>> adj(n);
           for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
           }

            vector<bool> vis(n ,false);
            int cnt = 1;
            dfs(0, adj, vis);

            for(int i=0;i<n;i++){
                if(!vis[i]){
                    cnt++;
                    dfs(i, adj, vis);
                }
            }

            return cnt;
    }
};
