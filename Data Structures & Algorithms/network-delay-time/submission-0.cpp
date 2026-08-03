#define P pair<int, int>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &it: times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        priority_queue<P, vector<P>, greater<P>> pq;

        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){

            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto& edge: adj[node]){

                int adjNode = edge.first;
                int edgeWt = edge.second;

                if(dis + edgeWt < dist[adjNode]){
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dis + edgeWt, adjNode});
                }
            }
        }

        int maxTime = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == 1e9) return -1;

            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
        

    }
};
