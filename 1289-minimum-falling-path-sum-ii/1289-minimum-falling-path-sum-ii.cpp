class Solution {
public:
    // Recursive solution gives TLE => Going for memoization
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> memo(m,vector<int>(n,INT_MAX)); // To store cached values
        int res=INT_MAX;
        for(int i=0;i<n;i++) res=min(res,findFallSum(0,i,matrix,memo,m,n));
        return res; 
    }
private:
    // Helper fn. to perform the memoization
    int findFallSum(int r, int c, vector<vector<int>>& mat, vector<vector<int>>& memo, int m, int n) {
        if(memo[r][c]!=INT_MAX) return memo[r][c];
        if(r==m-1) return memo[r][c]=mat[r][c];
        int min_fall=INT_MAX;
        for(int col=0;col<=n-1;col++) if(col!=c) min_fall=min(min_fall,findFallSum(r+1,col,mat,memo,m,n));
        return memo[r][c]=mat[r][c]+min_fall;
    }
};