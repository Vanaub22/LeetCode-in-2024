class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> safety(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]) {
                    q.push({i,j});
                    safety[i][j]=0;
                }
            }
        }
        // Multi-Source BFS
        while(!q.empty()) {
            auto [r,c]=q.front();
            q.pop();
            if(r+1<n && safety[r+1][c]>safety[r][c]+1) {
                safety[r+1][c]=safety[r][c]+1;
                q.push({r+1,c});
            }
            if(r-1>=0 && safety[r-1][c]>safety[r][c]+1) {
                safety[r-1][c]=safety[r][c]+1;
                q.push({r-1,c});
            }
            if(c-1>=0 && safety[r][c-1]>safety[r][c]+1) {
                safety[r][c-1]=safety[r][c]+1;
                q.push({r,c-1});
            }
            if(c+1<n && safety[r][c+1]>safety[r][c]+1) {
                safety[r][c+1]=safety[r][c]+1;
                q.push({r,c+1});
            }
        }
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({safety[0][0],{0,0}});
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        while(!pq.empty()) {
            int safeness=pq.top().first;
            auto [i,j]=pq.top().second;
            pq.pop();
            if(i==n-1 && j==n-1) return safeness;
            if(i+1<n && !visited[i+1][j]) {
                pq.push({min(safeness,safety[i+1][j]),{i+1,j}});
                visited[i+1][j]=true;
            }
            if(i-1>=0 && !visited[i-1][j]) {
                pq.push({min(safeness,safety[i-1][j]),{i-1,j}});
                visited[i-1][j]=true;
            }
            if(j+1<n && !visited[i][j+1]) {
                pq.push({min(safeness,safety[i][j+1]),{i,j+1}});
                visited[i][j+1]=true;
            }
            if(j-1>=0 && !visited[i][j-1]) {
                pq.push({min(safeness,safety[i][j-1]),{i,j-1}});
                visited[i][j-1]=true;
            }
        }
        return 0;
    }
};