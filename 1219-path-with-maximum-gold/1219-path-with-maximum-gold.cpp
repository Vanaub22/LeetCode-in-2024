class Solution {
public:
    // Constraints are small => Can go for Recursion
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),maxGold=0;
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) maxGold=max(maxGold,explore(i,j,m,n,grid));
        return maxGold;
    }
    int explore(int i, int j, int m, int n, vector<vector<int>>& grid) {
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0) return 0;
        int gold=grid[i][j];
        grid[i][j]=0; // To prevent revisits
        int up_col=explore(i-1,j,m,n,grid),left_col=explore(i,j-1,m,n,grid),down_col=explore(i+1,j,m,n,grid),right_col=explore(i,j+1,m,n,grid);
        grid[i][j]=gold; // Setting the right value again
        return grid[i][j]+max({up_col,down_col,left_col,right_col});
    }
};