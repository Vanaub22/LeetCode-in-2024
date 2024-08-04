#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,vector<pair<int,int>>> g;
        for(int i=0;i<n-1;i++) g[i].emplace_back(i+1,1);
        vector<int> answer;
        for(auto& query:queries) {
            int u=query[0],v=query[1];
            g[u].emplace_back(v,1);
            int shortestPath=dijkstra(0,n - 1,g, n);
            answer.push_back(shortestPath);
        }
        return answer;
    }

private:
    int dijkstra(int start, int end, unordered_map<int, vector<pair<int, int>>>& graph, int n) {
        vector<int> distances(n, INT_MAX);
        distances[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // min-heap
        pq.push({0, start});
        while (!pq.empty()) {
            int currentDist = pq.top().first;
            int current = pq.top().second;
            pq.pop();
            if (current == end) return currentDist;
            if (currentDist > distances[current]) continue;
            for (auto& [neighbor, weight]:graph[current]) {
                int newDist = currentDist + weight;
                if (newDist < distances[neighbor]) {
                    distances[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                }
            }
        }
        return -1;
    }
};
