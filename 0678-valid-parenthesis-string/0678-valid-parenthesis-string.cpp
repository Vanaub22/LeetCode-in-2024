// Recursive approach passes 79/83 test cases
// Memoizing the recursive solution (Top-Down DP)
class Solution {
private:
    bool check(int i, int open, auto& s, auto& memo, int n) {
        if(i==n) return !open;
        if(memo[i][open]!=-1) return memo[i][open];
        if(s[i]=='*') {
            if(open) return memo[i][open]=(check(i+1,open-1,s,memo,n) || check(i+1,open,s,memo,n) || check(i+1,open+1,s,memo,n));
            else return memo[i][open]=(check(i+1,open+1,s,memo,n) || check(i+1,open,s,memo,n));
        }
        else if(s[i]=='(') return memo[i][open]=check(i+1,open+1,s,memo,n);
        else if(open) return memo[i][open]=check(i+1,open-1,s,memo,n);
        else return memo[i][open]=0;
    }
public:
    bool checkValidString(string& s) {
        int n=s.size();
        vector<vector<int>> memo(n,vector<int>(n,-1));
        return check(0,0,s,memo,n);
    }
};