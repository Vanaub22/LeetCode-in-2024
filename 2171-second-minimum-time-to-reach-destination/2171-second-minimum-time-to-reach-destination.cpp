class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // Converting to adjacency list
        vector<int> adjList[n+1];
        for(auto& edge:edges) {
            adjList[edge[0]].emplace_back(edge[1]);
            adjList[edge[1]].emplace_back(edge[0]);
        }
        // Performing BFS
        queue<int> q;
        q.push(1);
        int current_time=0,best_time=-1; // Best time records the fastest path from 1 to n
        vector<vector<int>> visit_times(n+1); // To store all visit times
        while(!q.empty()) {
            int m=q.size();
            for(int i=0;i<m;i++) {
                int node=q.front();
                q.pop();
                if(node==n) {
                    if(best_time!=-1) return current_time; // The second minimum time to node n
                    best_time=current_time;
                }
                for(int neighbour:adjList[node]) {
                    if(visit_times[neighbour].empty() || visit_times[neighbour].size()==1 && visit_times[neighbour][0]!=current_time) {
                        q.push(neighbour);
                        visit_times[neighbour].emplace_back(current_time);
                    }
                }
            }
            if((current_time/change)%2) current_time+=change-(current_time%change); // Adding waiting time on encountering red signal
            current_time+=time; // Time taken to traverse the edge when signal is green
        }
        return -1;

    }
};