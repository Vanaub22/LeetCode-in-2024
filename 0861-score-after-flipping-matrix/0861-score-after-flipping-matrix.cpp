class Solution {
private:
    // Helper fn. to determine if current column needs to be flipped or not
    bool badCol(auto& grid, int c, int m) {
        int ones=0;
        for(int i=0;i<m;i++) if(grid[i][c]) ones++;
        return ones<=m/2;
    }
    // Helper fn. to flip the current row
    void flipRow(auto& grid, int r, int n) {
        for(int i=0;i<n;i++) grid[r][i]=grid[r][i]?0:1;
    }
    // Helper fn. to flip the current column
    void flipCol(auto& grid, int c, int m) {
        for(int i=0;i<m;i++) grid[i][c]=grid[i][c]?0:1;
    }
    // Helper fn. to calculate score, i.e. adding binary equivalent of each row
    int calcScore(auto& grid, int m, int n) {
        int score=0;
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) score+=pow(2,n-1-j)*grid[i][j];
        return score;
    }
public:
    // Greedy approach
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        // Making rows start with one to maximize score
        for(int i=0;i<m;i++) if(!grid[i][0]) flipRow(grid,i,n);
        // Flipping columns so that we can have more ones than zeroes
        for(int i=0;i<n;i++) if(badCol(grid,i,m)) flipCol(grid,i,m);
        return calcScore(grid,m,n);
    }
};