// Reversing the directed edges and then performing BFS to find all ancestors
class Solution {
private:
    // Helper fn. to find all the ancestors (i.e. children in the reversed graph) by performing BFS
    vector<int> findAncestors(int src, vector<int> adjList[], int n) {
        vector<int> ancestors;
        bool visited[n];
        memset(visited,false,sizeof(visited));
        queue<int> q;
        q.push(src);
        while(!q.empty()) {
            int qsize=q.size();
            for(int i=0;i<qsize;i++) {
                int node=q.front();
                q.pop();
                if(node!=src) ancestors.push_back(node);
                for(int adjNode:adjList[node]) {
                    if(!visited[adjNode]) {
                        visited[adjNode]=true;
                        q.push(adjNode);
                    }
                }
            }
        }
        sort(ancestors.begin(),ancestors.end());
        return ancestors;
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> answer;
        vector<int> adjList[n];
        // Reversing all the edges in the DAG
        for(auto edge:edges) adjList[edge[1]].push_back(edge[0]);
        for(int i=0;i<n;i++) answer.push_back(findAncestors(i,adjList,n));
        return answer;
    }
};