class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.length()+1,vector<int>(p.length()+1,-1));
        return check(s,p,0,0,memo);
    }
    bool check(string& s, string& p, int i, int j, vector<vector<int>>& memo) {
        if(j==p.length()) return memo[i][j]=i==s.length();
        if(memo[i][j]!=-1) return memo[i][j]==1;
        bool start=i<s.length() && (s[i]==p[j] || p[j]=='.');
        if(j<p.length()-1 && p[j+1]=='*') return memo[i][j]=check(s,p,i,j+2,memo) || start && check(s,p,i+1,j,memo);
        else return memo[i][j]=start && check(s,p,i+1,j+1,memo);
    }
};