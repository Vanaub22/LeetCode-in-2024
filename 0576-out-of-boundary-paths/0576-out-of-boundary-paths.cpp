#define MOD ((int)1e9+7)
#define v(x) vector<x>
class Solution {
public:
    // Recursion gives TLE => Memoization needed
    // 3 changing parameters in recursive calls => 3-D array will be needed to cache results
    int findPaths(int m, int n, int moves, int r, int c) {
        v(v(v(int))) memo(m,v(v(int))(n,v(int)(moves+1,-1)));
        return findMemoPaths(m,n,moves,r,c,memo);
    }
    int findMemoPaths(int m, int n, int moves, int r, int c, v(v(v(int)))& memo) {
        if(r<0 || c<0 || r>=m || c>=n) return 1;
        if(!moves) return memo[r][c][0]=0;
        if(memo[r][c][moves]!=-1) return memo[r][c][moves];
        return memo[r][c][moves]=(((findMemoPaths(m,n,moves-1,r+1,c,memo)+findMemoPaths(m,n,moves-1,r,c+1,memo)))%MOD+((findMemoPaths(m,n,moves-1,r-1,c,memo)+findMemoPaths(m,n,moves-1,r,c-1,memo)))%MOD)%MOD;
    }
};