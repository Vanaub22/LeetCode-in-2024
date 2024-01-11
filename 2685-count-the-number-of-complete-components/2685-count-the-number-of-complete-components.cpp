class Solution {
public:
    int countCompleteComponents(int m, vector<vector<int>>& edges) {
        vector<int> adjList[m];
        // Converting to adjacency list
        for(auto edge:edges) {
            adjList[edge[0]].emplace_back(edge[1]);
            adjList[edge[1]].emplace_back(edge[0]);
        }
        bool visited[m];
        memset(visited,false,sizeof(visited));
        int cnt=0;
        vector<vector<int>> components;
        for(int i=0;i<m;i++) {
            vector<int> members; // To store members of this component
            dfs(i,visited,members,adjList);
            if(!members.empty()) components.emplace_back(members);
        }
        for(auto component:components) {
            int n=component.size();
            bool complete=true;
            for(int i=0;i<n;i++) {
                if(adjList[component[i]].size()!=n-1) {
                    complete=false;
                    break;
                } 
            }
            if(complete) cnt++;
        }
        return cnt;
    }
    // Performing DFS on one component
    void dfs(int node, bool visited[], vector<int>& members, vector<int> adjList[]) {
        visited[node]=true;
        members.emplace_back(node);
        for(int neighbour:adjList[node]) if(!visited[neighbour]) dfs(neighbour,visited,members,adjList);
    }
};