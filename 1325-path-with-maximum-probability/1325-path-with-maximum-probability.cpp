class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int m=edges.size();
        vector<pair<int,double>> g[n];
        for(int i=0;i<m;i++) {
            int u=edges[i][0],v=edges[i][1];
            double w=succProb[i];
            g[u].push_back({v,w}),g[v].push_back({u,w});
        }
        double ans[n];
        bzero(ans,sizeof(ans)),ans[start_node]=1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start_node});
        while(!pq.empty()) {
            auto [prob,u]=pq.top();
            pq.pop();
            if(u==end_node) return prob;
            for(auto& [v,p]:g[u]) {
                if(prob*p>ans[v]) {
                    ans[v]=prob*p;
                    pq.push({ans[v],v});
                }
            }
        }
        return 0;
    }
};