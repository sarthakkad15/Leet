class Solution {
public:
    bool check(int n,int row,int col,vector<string>& sol)
    {
        if(row==0)
            return true;
        for(int i=0;i<row;i++)
        {
            if(sol[i][col]=='Q')
                return false;
        }
        int tempRow=row-1;
        int tempCol=col-1;
        while(tempRow>=0 && tempCol>=0)
        {
            if(sol[tempRow][tempCol]=='Q')
                return false;
            tempRow--;
            tempCol--;
        }
        tempRow=row-1;
        tempCol=col+1;
        while(tempRow>=0 && tempCol<n)
        {
            if(sol[tempRow][tempCol]=='Q')
                return false;
            tempRow--;
            tempCol++;
        }
        return true;
    }
    void solve(int n, int row, vector<string>& sol, vector<vector<string>>& ans)
    {
        if(row==n)
        {
            ans.push_back(sol);
            return;
        }
        for(int i=0;i<n;i++)
        {
            sol[row][i]='Q';
            if(check(n,row,i,sol))
                solve(n,row+1,sol,ans);
            sol[row][i]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> sol(n,string(n,'.'));
        vector<vector<string>> ans;
        solve(n,0,sol,ans);
        return ans;
    }
};