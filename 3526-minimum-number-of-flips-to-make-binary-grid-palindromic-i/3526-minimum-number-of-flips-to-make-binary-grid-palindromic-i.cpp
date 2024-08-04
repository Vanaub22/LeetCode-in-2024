class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),rowFlips=0,colFlips=0;
        for(auto& row:grid) {
            int flips=0;
            for(int c=0;c<n/2;c++) if(row[c]!=row[n-c-1]) flips++;
            rowFlips+=flips;
        }
        for(int c=0;c<n;c++) {
            int flips=0;
            for(int r=0;r<m/2;r++) if(grid[r][c]!=grid[m-r-1][c]) flips++;
            colFlips+=flips;
        }
        return min(rowFlips,colFlips);
    }
};