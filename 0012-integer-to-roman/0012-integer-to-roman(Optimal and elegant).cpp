class Solution {
public:
    vector<pair<char,int>> symbols;
    Solution()
    {
        symbols={{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}};
    }
    
    string intToRoman(int num) {
        string romanNumeral;
        
        for(int i=0;i<symbols.size();i++)
        {
            if(i%2==0)  // Powers of 10(1,10,100,..)
            {
                int cnt=num/symbols[i].second;
                if(cnt==4)
                {
                    romanNumeral+=symbols[i].first;
                    romanNumeral+=symbols[i-1].first;
                }
                else if(cnt==9)
                {
                    romanNumeral+=symbols[i].first;
                    romanNumeral+=symbols[i-2].first;
                }
                else
                {  
                    while(cnt--)
                        romanNumeral+=symbols[i].first;
                }
                num%=symbols[i].second;
            }
            else // 5*(Powers of 10) (5,50,500...)
            {
                int cnt=num/symbols[i].second;
                if(cnt && num<symbols[i-1].second-symbols[i+1].second)
                {
                    romanNumeral+=symbols[i].first;
                    num%=symbols[i].second;
                }
            }
        }
        return(romanNumeral);
    }
};

// T.C=O(1) ;   S.C=O(1)    (SINCE NUMERALS ARE FIXED AND FINITE)
// T.C=O(N) ;   S.C=O(N)    (IF O(N) ROMAN NUMERALS)
