class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<pair<int,int>> g[n+1];
        for(int i=0;i<n-1;i++) g[i].push_back({i+1,1});
        vector<int> answer;
        for(auto& query:queries) {
            int u=query[0],v=query[1];
            g[u].push_back({v,1});
            answer.push_back(dijkstra(0,n-1,g,n));
        }
        return answer;
    }
private:
    int dijkstra(int start, int end, vector<pair<int,int>> g[], int n) {
        vector<int> distances(n,INT_MAX);
        distances[start]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,start});
        while(!pq.empty()) {
            int currentDist=pq.top().first,current=pq.top().second;
            pq.pop();
            if(current==end) return currentDist;
            if(currentDist>distances[current]) continue;
            for(auto& entry:g[current]) {
                int neighbour=entry.first,weight=entry.second;
                int newDist=currentDist+weight;
                if(newDist<distances[neighbour]) {
                    distances[neighbour]=newDist;
                    pq.push({newDist,neighbour});
                }
            }
        }
        return -1;
    }
};
