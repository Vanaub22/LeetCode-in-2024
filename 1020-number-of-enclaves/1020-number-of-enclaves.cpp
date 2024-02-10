class Solution {
private:
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || visited[i][j] || !grid[i][j]) return;
        visited[i][j]=true;
        dfs(i+1,j,visited,grid);
        dfs(i-1,j,visited,grid);
        dfs(i,j+1,visited,grid);
        dfs(i,j-1,visited,grid);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),ans=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<n;i++) {
            if(grid[0][i] && !visited[0][i]) dfs(0,i,visited,grid);
            if(grid[m-1][i] && !visited[m-1][i]) dfs(m-1,i,visited,grid);
        }
        for(int i=0;i<m;i++) {
            if(grid[i][0] && !visited[i][0]) dfs(i,0,visited,grid); 
            if(grid[i][n-1] && !visited[i][n-1]) dfs(i,n-1,visited,grid); 
        }
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) if(grid[i][j] && !visited[i][j]) ans++;
        return ans;
    }
};