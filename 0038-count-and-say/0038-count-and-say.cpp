class Solution {
public:
    string countAndSay(int n) {
        string *p1=new string("1"),*p2=new string();

        // Finding solutions to successive values of 'i' upto 'n' iteratively
        for(int i=2;i<=n;i++)
        {
            int digit=(*p1)[0]-'0',pos=0;
            for(int j=0;j<=(*p1).size();j++)
            {
                if(j==(*p1).size() || (*p1)[j]-'0'!=digit)
                {
                    (*p2).push_back('0'+(j-pos)); // Count
                    (*p2).push_back('0'+digit);   // Character
                    if(j<(*p1).size())    
                    {
                        pos=j;
                        digit=(*p1)[j]-'0';
                    }
                }    
            }
            swap(p1,p2);
            (*p2).clear();
        }

        return(*p1);
    }
};

// T.C=O(4^(N/3)) ;   S.C=O(4^(N/3))(temporary extra string)
// PROOF(LC EDITORIAL)  ;   HOWEVER BOUND NOT TIGHT

// IMP - HERE DIGITS TAKE ONLY THE VALUE 1,2,3
// THUS ANSWER STRINGS CAN BE COMPRESSED TO USE 2 BITS FOR EACH DIGIT IF
// SPACE OPTIMIZATION IN STORAGE OF STRING REQUIRED 

// IMP - USING POINTERS TO OPTIMIZE TIME OF SWAPPING FOR SUCH CASES