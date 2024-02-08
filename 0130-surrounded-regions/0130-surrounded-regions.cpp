class Solution {
private:
    // Helper fn. to perform DFS and explore all the regions which will not be captured
    void dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<char>>& board, int m, int n) {
        if(r<0 || r>=m || c<0 || c>=n || board[r][c]!='O' || visited[r][c]) return;
        visited[r][c]=true;
        dfs(r+1,c,visited,board,m,n);
        dfs(r-1,c,visited,board,m,n);
        dfs(r,c+1,visited,board,m,n);
        dfs(r,c-1,visited,board,m,n);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        // If any region of O's is connected to a boundary O, then it will not be captured
        // Performing DFS to visit all regions which will not be captured
        for(int i=0;i<n;i++) {
            // For the first row
            if(!visited[0][i] && board[0][i]=='O') dfs(0,i,visited,board,m,n);
            // For the last row
            if(!visited[m-1][i] && board[m-1][i]=='O') dfs(m-1,i,visited,board,m,n);
        }
        for(int i=0;i<m;i++) {
            // For the first column
            if(!visited[i][0] && board[i][0]=='O') dfs(i,0,visited,board,m,n);
            // For the last column
            if(!visited[i][n-1] && board[i][n-1]=='O') dfs(i,n-1,visited,board,m,n);
        }
        // Capturing the surrounded regions
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) if(board[i][j]=='O' && !visited[i][j]) board[i][j]='X';
    }
};