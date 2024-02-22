#define v(type) vector<type>
class Solution {
private:
    int solve(int r1, int c1, int c2, int m, int n, auto& memo, auto& grid) {
        int cherries=0,dd,rr,dr,rd,r2=r1+c1-c2;
        if(r1>=m || r2>=m || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;
        else if(r1==m-1 && c1==n-1 && r2==r1 && c1==c2) return grid[m-1][n-1];
        else if(memo[r1][c1][c2]!=-1) return memo[r1][c1][c2];
        else if(r1==r2 && c1==c2) cherries+=grid[r1][c1];
        else cherries+=grid[r1][c1]+grid[r2][c2];
        dd=solve(r1+1,c1,c2,m,n,memo,grid);
        rr=solve(r1,c1+1,c2+1,m,n,memo,grid);
        dr=solve(r1+1,c1,c2+1,m,n,memo,grid);
        rd=solve(r1,c1+1,c2,m,n,memo,grid);
        return memo[r1][c1][c2]=cherries+max({dd,rr,rd,dr});
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        v(v(v(int))) memo(v(v(v(int)))(m,v(v(int))(n,v(int)(n,-1))));
        int ans=solve(0,0,0,m,n,memo,grid);
        return ans<0?0:ans; 
    }
};