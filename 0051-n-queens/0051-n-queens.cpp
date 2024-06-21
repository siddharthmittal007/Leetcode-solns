class Solution {
public:
    vector<vector<string>> ans;
    bool isValid(vector<string>& v,int index,int n)
    {
        int row=v.size(), column=index; // coordinates of queen to be added

        int col=column;         // To check if queen in same column
        int col_d1=column-row;  // To check if queen on same diagonal(TL to BR)
        int col_d2=row+column;  // To check if queen on same diagonal(TR to BL)
        
        // Checking each row for attacking queen
        for(int i=0;i<row;i++)
        {
            if(v[i][col]=='Q')
            {
                return(false); // Queen in same column
            }

            if(col_d1+i>=0 && v[i][col_d1+i]=='Q')
            {
                return(false); // Queen on same diagonal(TL to BR)
            }
            

            if(col_d2-i<n && v[i][col_d2-i]=='Q')
            {
                return(false); // Queen on same diagonal(TR to BL)
            }
        }
        
        return(true); // No queen attacking
    }
    
    void backtrack(int n,vector<string>& v,string& s)
    {
        // Base Case(saving solution)
        if(v.size()==n)
        {
            ans.push_back(v);
            return;
        }
        
        // Trying all possible positions of queen in current row
        for(int i=0;i<n;i++)
        {
            if(isValid(v,i,n))
            {
                s[i]='Q';           // Row with queen at (i+1)th position
                v.push_back(s);
                s[i]='.';
                
                backtrack(n,v,s);
                v.pop_back();
            }            

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v;
        string s(n,'.');
        backtrack(n,v,s);
        return(ans);
    }
};