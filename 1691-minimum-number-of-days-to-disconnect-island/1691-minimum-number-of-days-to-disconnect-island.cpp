class Solution {
private:
    void dfs(int i, int j, auto& grid, int m, int n, auto& visited) {
        if(i<0 || j<0 || i>=m || j>=n || !grid[i][j] || visited[i][j]) return;
        visited[i][j]=true;
        dfs(i+1,j,grid,m,n,visited);
        dfs(i-1,j,grid,m,n,visited);
        dfs(i,j+1,grid,m,n,visited);
        dfs(i,j-1,grid,m,n,visited);
    }
    int findIslandCnt(auto& grid, int m, int n) {
        int islands=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] && !visited[i][j]) {
                    islands++;
                    dfs(i,j,grid,m,n,visited);
                }
            }
        }
        return islands;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(findIslandCnt(grid,m,n)!=1) return 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]) {
                    grid[i][j]=0;
                    if(findIslandCnt(grid,m,n)!=1) return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};