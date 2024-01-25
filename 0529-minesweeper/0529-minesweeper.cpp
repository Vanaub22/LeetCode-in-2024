class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c) {
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size()) return;
        if(board[r][c]!='E') return;
        int mines=0; // To count eight-directionally adjacent mines
        if(c-1>=0 && board[r][c-1]=='M') mines++;
        if(c+1<board[0].size() && board[r][c+1]=='M') mines++;
        if(r+1<board.size()) {
            if(board[r+1][c]=='M') mines++;
            if(c-1>=0 && board[r+1][c-1]=='M') mines++;
            if(c+1<board[0].size() && board[r+1][c+1]=='M') mines++;
        }
        if(r-1>=0) {
            if(board[r-1][c]=='M') mines++;
            if(c-1>=0 && board[r-1][c-1]=='M') mines++;
            if(c+1<board[0].size() && board[r-1][c+1]=='M') mines++;
        }
        if(mines) board[r][c]='0'+mines;
        else {
            board[r][c]='B';
            dfs(board,r-1,c-1);
            dfs(board,r-1,c);
            dfs(board,r-1,c+1);
            dfs(board,r,c-1);
            dfs(board,r,c+1);
            dfs(board,r+1,c-1);
            dfs(board,r+1,c);
            dfs(board,r+1,c+1);
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]]=='M') board[click[0]][click[1]]='X';
        else dfs(board,click[0],click[1]);
        return board;
    }
};