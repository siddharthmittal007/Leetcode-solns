class Solution {
public:
    vector<pair<char,int>> symbols;
    
    Solution()
    {
        symbols={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};;
    }
    
    string intToRoman(int num) {
        string romanNumeral;
        
        for(int i=0;i<symbols.size();i++)
        {
            if(i%2==0)
            {
                int cnt=(num/symbols[i].second)%10;
                if(cnt==4)
                {
                    romanNumeral+=symbols[i+1].first;
                    romanNumeral+=symbols[i].first;
                }
                else if(cnt==9)
                {
                    romanNumeral+=symbols[i+2].first;
                    romanNumeral+=symbols[i].first;
                }
                else
                {  
                    cnt=cnt%5;
                    while(cnt--)
                    {
                        romanNumeral+=symbols[i].first;
                    }
                }
            }
            else // i%2==1
            {
                int cnt=(num/symbols[i].second)%2;
                if(cnt && num/symbols[i-1].second%10!=9)
                {
                    romanNumeral+=symbols[i].first;
                }
            }

        }

        reverse(romanNumeral.begin(),romanNumeral.end());

        return(romanNumeral);
    }
};