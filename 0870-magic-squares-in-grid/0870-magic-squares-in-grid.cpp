class Solution {
private:
    bool checkMagicSquares(auto& grid, int r, int c) {
        // Checking for rows and validity of numbers
        set<int> distinct;
        int targetSum=grid[r][c]+grid[r][c+1]+grid[r][c+2];
        for(int i=0;i<3;i++) {
            int rowSum=0;
            for(int j=0;j<3;j++) {
                int x=grid[r+i][c+j];
                rowSum+=x;
                if(distinct.find(x)==distinct.end() && x>=1 && x<=9) distinct.insert(x);
                else return false;
            }
            if(rowSum!=targetSum) return false;
        }
        // Checking for diagonals
        if(targetSum!=grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c] || targetSum!=grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]) return false;
        // Checking for columns
        for(int i=0;i<3;i++) {
            int colSum=0;
            for(int j=0;j<3;j++) colSum+=grid[r+j][c+i];
            if(colSum!=targetSum) return false;
        }
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),magicSquares=0;
        for(int i=0;i<m-2;i++) for(int j=0;j<n-2;j++) if(checkMagicSquares(grid,i,j)) magicSquares++;
        return magicSquares;
    }
};