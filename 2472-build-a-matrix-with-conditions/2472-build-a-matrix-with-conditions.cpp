class Solution {
public:
    vector<vector<int>> buildMatrix(int k, auto& rowConditions, auto& colConditions) {
        vector<int> rowAdjList[k+1],colAdjList[k+1];
        // Converting to adjacency list
        for(auto& edge:rowConditions) rowAdjList[edge[0]].emplace_back(edge[1]);
        for(auto& edge:colConditions) colAdjList[edge[0]].emplace_back(edge[1]);
        // Performing topological sort
        auto topologicalSort=[k](vector<int> g[])->vector<int> {
            int indegree[k+1];
            bzero(indegree,sizeof(indegree));
            for(int i=1;i<=k;i++) for(int j:g[i]) indegree[j]++;
            queue<int> q;
            for(int i=1;i<=k;i++) if(!indegree[i]) q.push(i);
            vector<int> order;
            while(!q.empty()) {
                int node=q.front();
                q.pop();
                order.emplace_back(node);
                for(int i:g[node]) {
                    indegree[i]--;
                    if(!indegree[i]) q.push(i);
                }
            }
            return order.size()==k?order:vector<int>{};
        };
        vector<int> rOrder=topologicalSort(rowAdjList),cOrder=topologicalSort(colAdjList);
        if(rOrder.empty() || cOrder.empty()) return {}; // Ordering Impossible => Cycle exists
        // Mapping values to their ordered positions
        unordered_map<int,int> rMap,cMap;
        for(int i=0;i<k;i++) rMap[rOrder[i]]=i;
        for(int i=0;i<k;i++) cMap[cOrder[i]]=i;
        // Creating resultant matrix
        vector<vector<int>> ans(k,vector<int>(k,0));
        for(int i=1;i<=k;i++) ans[rMap[i]][cMap[i]]=i;
        return ans;
    }
};