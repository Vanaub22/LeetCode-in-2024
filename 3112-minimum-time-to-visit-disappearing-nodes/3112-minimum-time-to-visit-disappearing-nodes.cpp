// Dijkstra's algorithm with added conditions for disappearance
// Implementation using priority queue passes 531/532 test cases
// Further optimization done by using std::set instead of priority queue
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int> ans;
        vector<pair<int,int>> adjList[n];
        int minTime[n];
        fill(minTime,minTime+n,INT_MAX);
        minTime[0]=0; // Source node
        for(auto edge:edges) {
            if(edge[0]==edge[1]) continue;
            adjList[edge[0]].push_back({edge[1],edge[2]});
            adjList[edge[1]].push_back({edge[0],edge[2]});
        }
        set<pair<int,int>> s;
        s.insert({0,0});
        while(!s.empty()) {
            auto [time,node]=*s.begin();
            s.erase(*s.begin());
            for(auto [neighbour,t]:adjList[node]) {
                // Checking if the node has already disappeared
                if(time+t<disappear[neighbour] && time+t<minTime[neighbour]) {
                    s.erase({minTime[neighbour],neighbour});
                    minTime[neighbour]=time+t;
                    s.insert({minTime[neighbour],neighbour});
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(minTime[i]>=INT_MAX) ans.emplace_back(-1); // Unreachable
            else ans.emplace_back(minTime[i]);
        }
        return ans;
    }
};