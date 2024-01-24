class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int> answer(n);
        for(int i=0;i<n;i++) answer[i]=i; // Each node is a valid answer for itself
        vector<int> adj[n];
        int indegree[n];
        memset(indegree,0,sizeof(indegree));
        // Converting to adjacency list
        for(auto& rel:richer) {
            int a=rel[0],b=rel[1];
            adj[a].push_back(b);
            indegree[b]++;
        }
        // Performing custom topological sort
        queue<int> q;
        for(int i=0;i<n;i++) if(!indegree[i]) q.push(i);
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            for(int neighbour:adj[node]) {
                if(quiet[node]<=quiet[neighbour]) {
                    answer[neighbour]=answer[node];
                    quiet[neighbour]=quiet[node];
                }
                indegree[neighbour]--;
                if(!indegree[neighbour]) q.push(neighbour);
            }
        }
        return answer;
    }
};