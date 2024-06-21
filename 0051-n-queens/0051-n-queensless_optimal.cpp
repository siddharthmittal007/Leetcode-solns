class Solution {
public:
    vector<vector<string>> ans;
    bool isValid(vector<string>& board,int row,int column,int n)
    {
        int col=column;         // To check if queen in same column
        int col_d1=column-row;  // To check if queen on same diagonal(TL to BR)
        int col_d2=row+column;  // To check if queen on same diagonal(TR to BL)
        
        // Checking each row for attacking queen
        for(int i=0;i<row;i++)
        {
            if(board[i][col]=='Q')
            {
                return(false); // Queen in same column
            }

            if(col_d1+i>=0 && board[i][col_d1+i]=='Q')
            {
                return(false); // Queen on same diagonal(TL to BR)
            }
            

            if(col_d2-i<n && board[i][col_d2-i]=='Q')
            {
                return(false); // Queen on same diagonal(TR to BL)
            }
        }
        
        return(true); // No queen attacking
    }
    
    void backtrack(int n,vector<string>& board,int row)
    {
        // Base Case(saving solution)
        if(row==n)
        {
            ans.push_back(board);
            return;
        }
        
        // Trying all possible positions of queen in current row
        for(int i=0;i<n;i++)
        {
            if(isValid(board,row,i,n))
            {
                board[row][i]='Q';
                backtrack(n,board,row+1);
                board[row][i]='.';
            }            

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string> board(n,s);
        backtrack(n,board,0);
        return(ans);
    }
};