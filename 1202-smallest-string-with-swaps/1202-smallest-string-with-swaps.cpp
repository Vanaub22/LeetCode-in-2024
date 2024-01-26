class Solution {
public:
    // Very tough intuition (Refer to hints)
    // Treat as a graph, perform DFS, sort each component based on swappable indices
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.length();
        vector<int> adjList[n];
        for(auto& pair:pairs) {
            adjList[pair[0]].emplace_back(pair[1]);
            adjList[pair[1]].emplace_back(pair[0]);            
        }
        bool visited[n];
        memset(visited,false,sizeof(visited));
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                vector<int> indices;
                vector<char> characters;
                dfs(i,indices,characters,visited,adjList,s);
                sort(characters.begin(),characters.end());
                sort(indices.begin(),indices.end());
                for(int j=0;j<characters.size();j++) s[indices[j]]=characters[j];
            }
        }
        return s;
    }
    void dfs(int node, vector<int>& indices, vector<char>& chars, bool visited[], vector<int> adjList[], string& s) {
        visited[node]=true;
        chars.emplace_back(s[node]);
        indices.emplace_back(node);
        for(int neighbour:adjList[node]) if(!visited[neighbour]) dfs(neighbour,indices,chars,visited,adjList,s);
    }
};