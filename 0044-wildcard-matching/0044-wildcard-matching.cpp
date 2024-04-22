// Recursive approach passes 936/1811 cases and then runs out of time
// Memoization will reduce the exponential T.C. to O(N x M) (Since there are N x M different states)
// S.C. will become O(N x M) + O(N + M) (For the 2D array and auxiliary stack space respectively)
class Solution {
private:
    bool compare(int i, int j, auto& s, auto& p, auto& memo) {
        if(i<0 && j<0) return true; // Exhausted together
        else if(i>=0 && j<0) return false; // No matching possible
        else if(i<0 && j>=0) {
            // String exhausted but pattern remains
            for(int k=0;k<=j;k++) if(p[k]!='*') return false;
            return true; // The remaining pattern [***] matches with empty string
        }
        if(memo[i][j]!=-1) return memo[i][j];
        // Matching characters at ith index of s and jth index of p
        else if(s[i]==p[j] || p[j]=='?') return memo[i][j]=compare(i-1,j-1,s,p,memo);
        // Trying to match '*' at jth index of p with s[0...i]
        else if(p[j]=='*') return memo[i][j]=compare(i-1,j,s,p,memo) || compare(i,j-1,s,p,memo);
        return memo[i][j]=false;
    }
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<int>> memo(vector<vector<int>>(m,vector<int>(n,-1)));
        return compare(m-1,n-1,s,p,memo);
    }
};