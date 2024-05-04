class Solution {
private:
    int helper(int i, int j, string& word1, string& word2, int m, int n, auto& memo) {
        if(i>=m) return n-j;
        if(j>=n) return m-i;
        if(memo[i][j]!=-1) return memo[i][j];
        if(word1[i]==word2[j]) return memo[i][j]=helper(i+1,j+1,word1,word2,m,n,memo);
        int insertion=helper(i,j+1,word1,word2,m,n,memo);
        int deletion=helper(i+1,j,word1,word2,m,n,memo);
        int replacement=helper(i+1,j+1,word1,word2,m,n,memo);
        return memo[i][j]=1+min({insertion,deletion,replacement});
    }
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> memo(m+1,vector<int>(n+1,-1));
        return helper(0,0,word1,word2,word1.size(),word2.size(),memo);
    }
};