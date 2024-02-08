class Solution {
public:
    // Converting Recursive approach (TLE) to Memoization
    int numSquares(int n) {
        int memo[n+1];
        memset(memo,-1,sizeof(memo));
        return gen(n,memo);
    }
    int gen(int n, int memo[]) {
        if(!n) return 0;
        else if(n<0) return INT_MAX;
        else if(memo[n]!=-1) return memo[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++) ans=min(ans,1+gen(n-i*i,memo));
        return memo[n]=ans;
    }
};