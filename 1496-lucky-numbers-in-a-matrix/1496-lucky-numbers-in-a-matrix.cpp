class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        vector<int> lucky;
        int m=mat.size(),n=mat[0].size(),i=0;
        int minInRow[m],maxInCol[n];
        bzero(maxInCol,sizeof(maxInCol));
        for(auto& row:mat) minInRow[i++]=*min_element(row.begin(),row.end());
        for(i=0;i<m;i++) for(int j=0;j<n;j++) maxInCol[j]=max(maxInCol[j],mat[i][j]);
        for(i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j]==minInRow[i] && mat[i][j]==maxInCol[j]) lucky.push_back(mat[i][j]);
            }
        }
        return lucky;
    }
};