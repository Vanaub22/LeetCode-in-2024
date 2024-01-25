class Solution {
public:
    int findLCS(int i, int j, string& a, string& b, vector<vector<int>>& memo) {
        if(i>=a.size() || j>=b.size()) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        if(a[i]==b[j]) return memo[i][j]=max({1+findLCS(i+1,j+1,a,b,memo),findLCS(i,j+1,a,b,memo),findLCS(i+1,j,a,b,memo)});
        else return memo[i][j]=max(findLCS(i,j+1,a,b,memo),findLCS(i+1,j,a,b,memo));
    }
    int longestCommonSubsequence(string a, string b) {
        vector<vector<int>> memo(a.size(),vector<int>(b.size(),-1));
        return findLCS(0,0,a,b,memo);
    }
};