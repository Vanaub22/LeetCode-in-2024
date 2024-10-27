class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),ans=0;
        vector<vector<int>> memo(m+1,vector<int>(n+1,-1));
        function<int(int,int)> solve=[&](int i, int j)->int {
            if(i<0 || j<0 || !matrix[i][j]) return 0;
            if(memo[i][j]!=-1) return memo[i][j];
            return memo[i][j]=1+min({solve(i-1,j),solve(i,j-1),solve(i-1,j-1)});
        };
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) ans+=solve(i,j);
        return ans;
    }
};