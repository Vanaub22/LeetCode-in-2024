class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),ans=-1;
        vector<vector<int>> memo=vector<vector<int>>(m+1,vector<int>(n+1,-1));
        function<int(int,int)> helper=[&helper,&matrix,&memo,m,n](int i, int j)->int{
            if(i>=m || j>=n) return memo[i][j]=0;
            if(memo[i][j]!=-1) return memo[i][j];
            int calcRight=helper(i,j+1),calcDown=helper(i+1,j),calcDiag=helper(i+1,j+1);
            return memo[i][j]=matrix[i][j]-'0'?1+min({calcRight,calcDown,calcDiag}):0;
        };
        helper(0,0);
        for(auto& row:memo) ans=max(ans,(int)pow(*max_element(row.begin(),row.end()),2));
        return ans;
    }
};