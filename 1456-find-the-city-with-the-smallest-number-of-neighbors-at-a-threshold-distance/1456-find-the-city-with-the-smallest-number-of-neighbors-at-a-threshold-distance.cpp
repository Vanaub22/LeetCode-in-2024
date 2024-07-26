class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> adjList[n];
        // Converting to adjacency list
        for(auto& edge:edges) {
            int u=edge[0],v=edge[1],w=edge[2];
            // Bi-directional
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        int ans=-1,min_reachable_cities=INT_MAX;
        for(int city=0;city<n;city++) {
            // Applying Dijkstra's Algorithm
            int reachable_cities=0,distances[n];
            fill(distances,distances+n,INT_MAX);
            distances[city]=0;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,city});
            while(!pq.empty()) {
                auto [weight,u]=pq.top();
                pq.pop();
                for(auto& it:adjList[u]) {
                    auto& [v,w]=it;
                    if(distances[v]>w+weight) {
                        distances[v]=w+weight;
                        pq.push({distances[v],v});
                    }
                }
            }
            // Finding the number of reachable cities
            for(int i=0;i<n;i++) if(distances[i]<=distanceThreshold) reachable_cities++;
            // Checking if this city has lesser number of cities at threshold distance
            if(reachable_cities<=min_reachable_cities) {
                min_reachable_cities=reachable_cities;
                ans=city;
            }
        }
        return ans;
    }
};