// Recursive approach passes 79/83 test cases
// Memoizing the recursive solution (Top-Down DP)
class Solution {
private:
    bool check(int i, int open, auto& s, auto& memo, int n) {
        if(i==n) return !open;
        if(memo[i][open]!=-1) return memo[i][open];
        bool vps=false;
        if(s[i]=='*') {
            if(open) vps|=(check(i+1,open-1,s,memo,n) || check(i+1,open,s,memo,n) || check(i+1,open+1,s,memo,n));
            else vps|=(check(i+1,open+1,s,memo,n) || check(i+1,open,s,memo,n));
        }
        else if(s[i]=='(') vps=check(i+1,open+1,s,memo,n);
        else if(open) vps=check(i+1,open-1,s,memo,n);
        return memo[i][open]=vps;
    }
public:
    bool checkValidString(string& s) {
        int n=s.size();
        vector<vector<int>> memo(n,vector<int>(n,-1));
        return check(0,0,s,memo,n);
    }
};