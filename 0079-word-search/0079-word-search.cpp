class Solution {
private:
    bool dfs_check(auto& board, int i, int j, int m, int n, auto& word, int k, int l, auto& vis) {
        if(k>=l) return true;
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[k] || vis[i][j]) return false;
        else {
            vis[i][j]=true;
            bool found=dfs_check(board,i+1,j,m,n,word,k+1,l,vis) || dfs_check(board,i-1,j,m,n,word,k+1,l,vis) || dfs_check(board,i,j+1,m,n,word,k+1,l,vis) || dfs_check(board,i,j-1,m,n,word,k+1,l,vis);                                                                                                 
            vis[i][j]=false; // Backtracking
            return found;
        }
    }
public:
    bool exist(auto& board, string word) {
        int m=board.size(),n=board[0].size(),l=word.size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j]==word[0]) {
                    vector<vector<bool>> vis(m,vector<bool>(n,false));
                    if(dfs_check(board,i,j,m,n,word,0,l,vis)) return true;
                }
            }
        }
        return false;
        
    }
};