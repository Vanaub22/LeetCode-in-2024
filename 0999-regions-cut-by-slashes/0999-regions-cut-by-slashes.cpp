class Solution {
private:
    void bfs(int r, int c, auto& g, int n, auto& visited) {
        visited[r][c]=true;
        queue<pair<int,int>> q;
        q.push({r,c});
        while(!q.empty()) {
            auto [i,j]=q.front();
            q.pop();
            if(i+1<n && !g[i+1][j] && !visited[i+1][j]) {
                q.push({i+1,j});
                visited[i+1][j]=true;
            }
            if(j+1<n && !g[i][j+1] && !visited[i][j+1]) {
                q.push({i,j+1});
                visited[i][j+1]=true;
            }
            if(i-1>=0 && !g[i-1][j] && !visited[i-1][j]) {
                q.push({i-1,j});
                visited[i-1][j]=true;
            }
            if(j-1>=0 && !g[i][j-1] && !visited[i][j-1]) {
                q.push({i,j-1});
                visited[i][j-1]=true;
            }
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size(),components=0;
        // Creating a magnified graph of 0's and 1's
        vector<vector<int>> g(n*3,vector<int>(n*3,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]=='/') g[i*3][j*3+2]=1,g[i*3+1][j*3+1]=1,g[i*3+2][j*3]=1;
                else if(grid[i][j]=='\\') g[i*3][j*3]=1,g[i*3+1][j*3+1]=1,g[i*3+2][j*3+2]=1;
            }
        }
        // Counting number of components
        vector<vector<bool>> visited(n*3,vector<bool>(n*3,false));
        for(int i=0;i<n*3;i++) {
            for(int j=0;j<n*3;j++) {
                if(!visited[i][j] && g[i][j]==0) {
                    bfs(i,j,g,n*3,visited);
                    components++;
                }
            }
        }
        return components;
    }
};