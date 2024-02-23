// Modified Dijkstra's algorithm approach. Considering number of stops as a constraint.
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adjList[n];
        for(auto& entry:flights) adjList[entry[0]].emplace_back(make_pair(entry[1],entry[2]));
        int price[n]; // To store prices to visit each node
        fill(price,price+n,INT_MAX);
        queue<pair<int,pair<int,int>>> q;
        q.push(make_pair(0,make_pair(src,0)));
        while(!q.empty()) {
            auto entry=q.front();
            q.pop();
            int stops=entry.first,node=entry.second.first,cost=entry.second.second;
            if(stops>k) continue; // Too many stops => Not considered
            for(auto& neighbour:adjList[node]) {
                int destNode=neighbour.first,edge_weight=neighbour.second;
                if(cost+edge_weight<price[destNode] && stops<=k) {
                    // Getting a better path at a lesser price with a valid number of stops
                    price[destNode]=cost+edge_weight;
                    q.push(make_pair(stops+1,make_pair(destNode,cost+edge_weight)));
                }
            }
        }
        return price[dst]==INT_MAX?-1:price[dst];
    }
};