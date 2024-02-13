class Solution {
private:
    void dfs(int node, vector<int> adjList[], bool vis[], int& component_size) {
        if(vis[node]) return;
        vis[node]=true;
        component_size++;
        for(int neighbour:adjList[node]) {
            if(!vis[neighbour]) dfs(neighbour,adjList,vis,component_size);
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        if(edges.empty()) return (long long)n*(n-1)/2;
        long long unreachable_pairs=0;
        vector<int> adjList[n];
        for(auto& edge:edges) {
            adjList[edge[0]].emplace_back(edge[1]);
            adjList[edge[1]].emplace_back(edge[0]); 
        }
        bool vis[n];
        memset(vis,false,n);
        vector<long long> component_sizes;
        for(int i=0;i<n;i++) {
            int component_size=0;
            if(!vis[i]) {
                dfs(i,adjList,vis,component_size);
                for(long long x:component_sizes) unreachable_pairs+=x*component_size;
                component_sizes.emplace_back(component_size);
            }
        }
        return unreachable_pairs;
    }
};