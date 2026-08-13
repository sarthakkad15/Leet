class Solution {
public:
    bool check(vector<vector<char>>& board, int row, int col)
    {
        for(int i=0;i<9;i++)
        {
            if(i==col)
                continue;
            if(board[row][col]==board[row][i])
                return false;
        }
        for(int i=0;i<9;i++)
        {
            if(i==row)
                continue;
            if(board[row][col]==board[i][col])
                return false;
        }
        int r=(row/3)*3;
        int c=(col/3)*3;
        for(int i=r;i<r+3;i++)
        {
            for(int j=c;j<c+3;j++)
            {
                if(i==row && j==col)
                    continue;
                if(board[i][j]==board[row][col])
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int row, int col)
    {
        if(col==9)
            return solve(board,row+1,0);
        if(row==9)
            return true;
        if(board[row][col]!='.')
            return solve(board,row,col+1);
        else
        {
            for(int i=1;i<=9;i++)
            {
                board[row][col]='0'+i;
                if(check(board,row,col))
                {
                    if(solve(board,row,col+1))
                        return true;
                }
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};