// Modified Dijkstra's algorithm approach with time as edge weights
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> g(n);
        vector<int> knowing;
        // Converting to bi-directional weighted graph
        for(auto& meeting:meetings) {
            g[meeting[0]].push_back({meeting[1],meeting[2]});
            g[meeting[1]].push_back({meeting[0],meeting[2]});
        }
        bool knows[n];
        memset(knows,false,n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0}); // 0 knows
        pq.push({0,firstPerson}); // firstPerson knows
        while(!pq.empty()) {
            auto entry=pq.top();
            pq.pop();
            int time=entry.first,person=entry.second;
            if(knows[person]) continue;
            knows[person]=true;
            for(auto& x:g[person]) {
                if(knows[x.first]) continue;
                if(x.second>=time) pq.push({x.second,x.first});
            }
        }
        for(int i=0;i<n;i++) if(knows[i]) knowing.push_back(i);
        return knowing;
    }
};