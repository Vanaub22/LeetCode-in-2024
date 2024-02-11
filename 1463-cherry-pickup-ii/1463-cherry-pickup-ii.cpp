#define v(type) vector<type>
// Recursion passes 29/39 test cases (Needs time optimization)
// 3-D DP Memoization (Top-Down Approach)
class Solution {
private:
    int solve(int i, int j1, int j2, int m, int n, v(v(int))& grid, v(v(v(int)))& memo) {
        if(j1<0 || j1>=n || j2<0 || j2>=n) return 0; // Moved out of the boundary
        int cherries=j1==j2?grid[i][j1]:grid[i][j1]+grid[i][j2]; // Cherries picked in this row by both robots
        if(i==m-1) return cherries; // Reached the last row
        if(memo[i][j1][j2]!=-1) return memo[i][j1][j2];
        // Exploring all possible paths (9 possible combinations for each (i,j1) and (i,j2))
        int maxCherries=0;
        for(int dj1=-1;dj1<2;dj1++) {
            for(int dj2=-1;dj2<2;dj2++) {
                maxCherries=max(maxCherries,cherries+solve(i+1,j1+dj1,j2+dj2,m,n,grid,memo));                
            }
        }
        return memo[i][j1][j2]=maxCherries;
    }
public:
    int cherryPickup(v(v(int))& grid) {
        int m=grid.size(),n=grid[0].size();
        v(v(v(int))) memo(m,v(v(int))(n,v(int)(n,-1)));
        return solve(0,0,n-1,m,n,grid,memo);
    }
};