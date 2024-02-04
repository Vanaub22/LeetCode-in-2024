class Solution {
public:
    int minDistance(string& a, string& b) {
        int m=a.size(),n=b.size();
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return m+n-2*lcs(a,b,0,0,m,n,memo);
    }
    // Finding out the longest common subsequence using memoization
    int lcs(string& a, string& b, int i, int j, int m, int n, vector<vector<int>>& memo) {
        if(i>=m || j>=n) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        if(a[i]==b[j]) return memo[i][j]=1+lcs(a,b,i+1,j+1,m,n,memo);
        else return memo[i][j]=max(lcs(a,b,i+1,j,m,n,memo),lcs(a,b,i,j+1,m,n,memo));
    }
};