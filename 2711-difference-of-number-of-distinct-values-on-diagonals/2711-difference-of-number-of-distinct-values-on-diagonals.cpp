class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int r=0;r<m;r++) {
            for(int c=0;c<n;c++) {
                int i=r-1,j=c-1;
                set<int> upper_left,lower_right;
                while(i>=0 && j>=0) {
                    upper_left.insert(grid[i][j]);
                    i--;
                    j--;
                }
                i=r+1,j=c+1;
                while(i<m && j<n) {
                    lower_right.insert(grid[i][j]);
                    i++;
                    j++;
                }
                ans[r][c]=abs((int)(upper_left.size()-lower_right.size()));
            }
        }
        return ans;
    }
};