class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if(n==1) {
            ans.emplace_back(0);
            return ans;
        }
        int degree[n];
        bzero(degree,sizeof(degree));
        vector<int> adjList[n];
        // Creating adjacency list and calculating degree for each node
        for(auto& edge:edges) {
            adjList[edge[0]].emplace_back(edge[1]);
            adjList[edge[1]].emplace_back(edge[0]);
            degree[edge[0]]++,degree[edge[1]]++;
        }
        queue<int> q;
        // Finding out nodes with degree 1
        for(int i=0;i<n;i++) if(degree[i]==1) q.push(i);
        // Performing BFS and removing nodes with indegree 1 at each iteration
        while(n>2) {
            n-=q.size(); // Nodes with degree 1 cannot be roots for Minimum Height Trees
            int qsize=q.size();
            for(int i=0;i<qsize;i++) {
                int node=q.front();
                q.pop();
                for(int neighbour:adjList[node]) {
                    degree[neighbour]--;
                    if(degree[neighbour]==1) q.push(neighbour);
                }
            }
        }
        // All nodes with degree 1 remaining in the queue are valid roots for Minimum Height Trees
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans; 
    }
};