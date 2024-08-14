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
            if(i%2==0)
            {
                int cnt=num/symbols[i].second;
                if(cnt==4)
                {
                    romanNumeral+=symbols[i].first;
                    romanNumeral+=symbols[i-1].first;
                }
                else
                {  
                    while(cnt--)
                        romanNumeral+=symbols[i].first;
                }
                num%=symbols[i].second;
            }
            else // i%2==1
            {
                int cnt=num/symbols[i].second;
                if(num>=symbols[i-1].second-symbols[i+1].second)
                {
                    romanNumeral+=symbols[i+1].first;
                    romanNumeral+=symbols[i-1].first;
                    num%=symbols[i+1].second;
                }
                else if(cnt)
                {
                    romanNumeral+=symbols[i].first;
                    num%=symbols[i].second;
                }
            }
        }

        return(romanNumeral);
    }
};