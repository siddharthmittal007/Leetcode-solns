class Solution {
public:    
    bool backtrack(vector<vector<char>>& board,int index,vector<vector<bool>>& row,vector<vector<bool>>& column,vector<vector<bool>>& square)
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
            if(row[r][i]==true || column[c][i]==true || square[s][i]==true)
            {
                continue; // Placement invalid
            }

            // Placement valid
            board[r][c]='1'+i;
            row[r][i]=column[c][i]=square[s][i]=true;

            if(backtrack(board,index+1,row,column,square)==true)
            {
                return(true);
            }
            
            board[r][c]='.';    
            row[r][i]=column[c][i]=square[s][i]=false;
            
        }

        return(false);
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        // Vectors to hold occupancy of digits by rows, columns and squares
        vector<vector<bool>> row(9,vector<bool>(9,false));
        vector<vector<bool>> column(9,vector<bool>(9,false));
        vector<vector<bool>> square(9,vector<bool>(9,false));
        
        // Marking occurence of digits in given filled cells
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    row[i][board[i][j]-'1']=true;
                    column[j][board[i][j]-'1']=true;
                    square[i-(i%3)+j/3][board[i][j]-'1']=true;
                }
                
            }
        }

        backtrack(board,0,row,column,square); // Beginning solving from 0th index
    }
};