class Solution {
private:
    void dfs(int src, vector<int> adjList[], bool vis[]) {
        if(vis[src]) return;
        vis[src]=true;
        for(int neighbour:adjList[src]) if(!vis[neighbour]) dfs(neighbour,adjList,vis);
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<int> adjList[n];
        for(auto& edge:edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        bool vis[n];
        bzero(vis,sizeof(vis));
        dfs(src,adjList,vis);
        return vis[dest];
    }
};