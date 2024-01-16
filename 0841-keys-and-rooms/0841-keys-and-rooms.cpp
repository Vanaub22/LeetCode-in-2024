class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        bool visited[n];
        memset(visited,false,sizeof visited);
        dfs(0,rooms,visited);
        for(int i=0;i<n;i++) if(!visited[i]) return false;
        return true;
    }
    // Helper fn. to perform DFS
    void dfs(int room, vector<vector<int>>& rooms, bool visited[]) {
        if(visited[room]) return;
        visited[room]=true;
        for(int key:rooms[room]) dfs(key,rooms,visited);
    }
};