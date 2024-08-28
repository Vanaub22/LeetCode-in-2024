class Solution {
private:
    bool dfs(int r, int c, int m, int n, auto& visited, auto& grid1, auto& grid2) {
        if(r<0 || r>=m || c<0 || c>=n || visited[r][c] || !grid2[r][c]) return true;
        visited[r][c]=true;
        bool left,right,up,down;
        down=dfs(r+1,c,m,n,visited,grid1,grid2);
        right=dfs(r,c+1,m,n,visited,grid1,grid2);
        up=dfs(r-1,c,m,n,visited,grid1,grid2);
        left=dfs(r,c-1,m,n,visited,grid1,grid2);
        return grid1[r][c] && up && down && left && right;
    }
public:
    int countSubIslands(auto& grid1, auto& grid2) {
        int m=grid1.size(),n=grid1[0].size(),subislands=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!visited[i][j] && grid2[i][j]) {
                    if(dfs(i,j,m,n,visited,grid1,grid2)) subislands++;
                }
            }
        }
        return subislands;
    }
};