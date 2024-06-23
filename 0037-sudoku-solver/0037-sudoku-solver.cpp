class Solution {
public:    
    bool backtrack(vector<vector<char>>& board,int index,vector<int>& row,vector<int>& column,vector<int>& square)
    {
        if(index==9*9) 
        {
            return(true); // Solution found
        }

        // Row, column and square of current index
        int r=index / 9;
        int c=index % 9;
        int s=r-(r%3) + c/3;

        if(board[r][c]!='.') // Index already filled
        {
            return(backtrack(board,index+1,row,column,square)); // Proceed to next index
        }
        
        // Checking each digit from 1-9 for valid placement
        for(int i=0;i<9;i++)
        {
            if((row[r]&(1<<i))==0 && (column[c]&(1<<i))==0 && (square[s]&(1<<i))==0)
            {
                // Placement valid
                board[r][c]='1'+i;
                row[r]|=1<<i;
                column[c]|=1<<i;
                square[s]|=1<<i;

                if(backtrack(board,index+1,row,column,square)==true)
                {
                    return(true);
                }
            
                board[r][c]='.';    
                row[r]&=~(1<<i);
                column[c]&=~(1<<i);
                square[s]&=~(1<<i);
            }
        }

        return(false);
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        // Vectors of integers to hold occupancy of digits by rows, columns
        // and squares in integer bits
        vector<int> row(9,0);
        vector<int> column(9,0);
        vector<int> square(9,0);
        
        // Marking occurence of digits in given filled cells
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    row[i]|=(1<<board[i][j]-'1');
                    column[j]|=(1<<board[i][j]-'1');
                    square[3*(i/3)+j/3]|=(1<<board[i][j]-'1');
                }
                
            }
        }

        backtrack(board,0,row,column,square); // Beginning solving from 0th index
    }
};