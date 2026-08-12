class Solution {
public:
    bool check(vector<vector<char>>& board, string word, int row, int col, int m, int n, int idx)
    {
        if(row<0 || col<0 || row>=m || col>=n)
            return false;
        if(board[row][col]!=word[idx])
            return false;
        if(idx==word.size()-1)
            return true;
        char temp = board[row][col];
        board[row][col] = '#';
        if(check(board,word,row+1,col,m,n,idx+1) || check(board,word,row-1,col,m,n,idx+1) || check(board,word,row,col+1,m,n,idx+1) || check(board,word,row,col-1,m,n,idx+1))
            return true;
        board[row][col] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0] && check(board,word,i,j,m,n,0))
                    return true;
            }
        }
        return false;
    }
};