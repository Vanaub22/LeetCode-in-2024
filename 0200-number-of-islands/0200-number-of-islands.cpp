class Solution {
private:
    void bfs(int row, int col, int m, int n, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col]=true;
        while(!q.empty()) {
            int r=q.front().first,c=q.front().second;
            q.pop();
            if(r>0 && grid[r-1][c]=='1' && !visited[r-1][c]) {
                visited[r-1][c]=true;
                q.push({r-1,c});
            }
            if(r<m-1 && grid[r+1][c]=='1' && !visited[r+1][c]) {
                visited[r+1][c]=true;
                q.push({r+1,c});
            }
            if(c>0 && grid[r][c-1]=='1' && !visited[r][c-1]) {
                visited[r][c-1]=true;
                q.push({r,c-1});
            }
            if(c<n-1 && grid[r][c+1]=='1' && !visited[r][c+1]) {
                visited[r][c+1]=true;
                q.push({r,c+1});
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size(),islands=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        if(grid[i][j]=='1' && !visited[i][j]) {
            islands++;
            bfs(i,j,m,n,visited,grid);
        }
        return islands;
    }
};