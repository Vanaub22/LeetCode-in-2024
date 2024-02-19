// Finding the LCS in the original string and the reversed string to yield the LPS
class Solution {
private:
    int solve(int i, int j, string& s, string& r, vector<vector<int>>& memo, int n) {
        if(i>=n || j>=n) return 0;
        else if(memo[i][j]!=-1) return memo[i][j];
        else if(s[i]==r[j]) return memo[i][j]=1+solve(i+1,j+1,s,r,memo,n);
        else return memo[i][j]=max({solve(i+1,j+1,s,r,memo,n),solve(i+1,j,s,r,memo,n),solve(i,j+1,s,r,memo,n)});
    }
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>> memo(n,vector<int>(n,-1));
        string r=s;
        reverse(r.begin(),r.end());
        return solve(0,0,s,r,memo,n);
    }
};