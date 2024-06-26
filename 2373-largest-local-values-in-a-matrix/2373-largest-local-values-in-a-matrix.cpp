class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> ans(n-2,vector<int>(n-2,-1));
        for(int i=1;i<=n-2;i++) {
            for(int j=1;j<=n-2;j++) {
                for(int x=i-1;x<=i+1;x++) {
                    for(int y=j-1;y<=j+1;y++) ans[i-1][j-1]=max(ans[i-1][j-1],grid[x][y]);
                }
            }
        }
        return ans;
    }
};