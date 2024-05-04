class Solution {
private:
    int dp(int i, int j, string& word1, string& word2, int m, int n, auto& memo) {
        if(i>=m) return n-j;
        if(j>=n) return m-i;
        if(memo[i][j]!=-1) return memo[i][j];
        if(word1[i]==word2[j]) return memo[i][j]=dp(i+1,j+1,word1,word2,m,n,memo);
        int insertion=dp(i,j+1,word1,word2,m,n,memo);
        int deletion=dp(i+1,j,word1,word2,m,n,memo);
        int replacement=dp(i+1,j+1,word1,word2,m,n,memo);
        return memo[i][j]=1+min({insertion,deletion,replacement});
    }
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> memo(m+1,vector<int>(n+1,-1));
        return dp(0,0,word1,word2,word1.size(),word2.size(),memo);
    }
};