class Solution {
public:    
    bool isValid(vector<vector<char>>& board,int r,int c,int num)
    {
        // Checking if number already occupies the same row, column or square
        for(int i=0;i<9;i++)
        {
            if  (board[r][i]=='0'+num || board[i][c]=='0'+num || 
                board[3*(r/3)+i/3][3*(c/3)+i%3]=='0'+num)
            {
                return(false); // Number already present
            }
        }
        return(true); // Number absent
    }
    
    bool backtrack(vector<vector<char>>& board,int index)
    {
        if(index==9*9) 
        {
            return(true); // Solution found
        }

        // Row and column of current index
        int r=index / 9;
        int c=index % 9;

        if(board[r][c]!='.') // Index already filled
        {
            return(backtrack(board,index+1)); // Proceed to next index
        }
        
        // Checking each digit from 1-9 for valid placement
        for(int i=1;i<=9;i++)
        {
            if(isValid(board,r,c,i))
            {
                board[r][c]='0'+i;
                if(backtrack(board,index+1)==true)
                {
                    return(true);
                }
                board[r][c]='.';    
            }
        }

        return(false);
    }
    
    void solveSudoku(vector<vector<char>>& board) { 
        backtrack(board,0); // Begin solving from 0th index
    }
};