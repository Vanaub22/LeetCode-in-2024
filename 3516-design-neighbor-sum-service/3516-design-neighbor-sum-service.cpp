class neighborSum {
public:
    int m,n;
    vector<vector<int>> grid;
    neighborSum(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        this->grid=grid;
    }

    int adjacentSum(int value) {
        int r=-1,c=-1;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==value) {
                    r=i,c=j;
                    break;
                }
                if(r!=-1) break;
            }
        }
        if(r==-1) return 0;
        int ans=0;
        if(r+1<m) ans+=grid[r+1][c];
        if(r-1>=0) ans+=grid[r-1][c];
        if(c-1>=0) ans+=grid[r][c-1];
        if(c+1<n) ans+=grid[r][c+1];
        return ans;
    }
    
    int diagonalSum(int value) {
        int r=-1,c=-1;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==value) {
                    r=i,c=j;
                    break;
                }
                if(r!=-1) break;
            }
        }
        if(r==-1) return 0;
        int ans=0;
        if(r+1<m && c+1<n) ans+=grid[r+1][c+1];
        if(r-1>=0 && c-1>=0) ans+=grid[r-1][c-1];
        if(c-1>=0 && r+1<m) ans+=grid[r+1][c-1];
        if(c+1<n && r-1>=0) ans+=grid[r-1][c+1];
        return ans;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */