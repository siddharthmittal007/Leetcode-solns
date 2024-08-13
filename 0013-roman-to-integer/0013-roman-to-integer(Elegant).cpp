class Solution {
public:
    unordered_map<char,int> ump;
    
    Solution()
    {
        ump={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    }
    
    int symbolValue(char c)
    {
        return(ump[c]);
        
    }
    
    int romanToInt(string s) {
        int value=0;
        for(int i=0;i<s.size();i++)
        {
            if(i==s.size()-1 || symbolValue(s[i])>=symbolValue(s[i+1]))
                value+=symbolValue(s[i]);
            else
                value-=symbolValue(s[i]);
        }

        return(value);
    }
};

// T.C=O(1) ;   S.C=O(1)       (STRING LENGTH BOUND TO LENGTH OF 3888)
// T.C=O(N) ;   S.C=O(N)        (IF N NUMBER OF SYMBOLS GIVEN)
