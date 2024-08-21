class Solution {
public:
int strangePrinter(string s) {
        int n=s.size();
        vector<vector<int>> memo(n,vector<int>(n,-1));
        return dp(s,0,n-1,memo);
    }
private:
    int dp(string& s, int i, int j, vector<vector<int>>& memo) {
        if(i>j) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int ans=dp(s,i+1,j,memo)+1;
        for(int k=i+1;k<=j;k++) if(s[k]==s[i]) ans=min(ans,dp(s,i,k-1,memo)+dp(s,k+1,j,memo));
        memo[i][j]=ans;
        return ans;
    }
};