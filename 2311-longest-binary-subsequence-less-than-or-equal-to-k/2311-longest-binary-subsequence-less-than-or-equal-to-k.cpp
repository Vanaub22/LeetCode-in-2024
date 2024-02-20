class Solution {
private:
    int solve(int i, int len, string& s, int k, auto& memo) {
        if(i<0) return 0;
        if(memo[i][len]!=-1) return memo[i][len];
        int take=0,not_take=solve(i-1,len,s,k,memo);
        if(k-(s[i]-'0')*pow(2,len)>=0) take=1+solve(i-1,len+1,s,k-(s[i]-'0')*pow(2,len),memo);
        return memo[i][len]=max(take,not_take);
    }
public:
    int longestSubsequence(string s, int k) {
        int n=s.length();
        vector<vector<int>> memo(n,vector<int>(n,-1));
        return solve(n-1,0,s,k,memo);
    }
};