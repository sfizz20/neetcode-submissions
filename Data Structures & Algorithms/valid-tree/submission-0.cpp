class Solution {
private:

    void dfs(int node, vector<vector<int>>& adj, int n, vector<bool>& vis){

        vis[node] = true;

        for(int it : adj[node]){
            if(!vis[it]){
            dfs(it, adj, n, vis);
            }
        }
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n, false);
        dfs(0, adj, n, vis);

        for(int i=0; i<n; i++){
            if(!vis[i]){return false;}
        }

        return true;
    }
};
