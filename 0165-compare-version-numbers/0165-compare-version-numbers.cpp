class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        while(i<version1.size() || j<version2.size())
        {
            // Evaluate current revisions
            int val1=0,val2=0;
            while(i<version1.size() && version1[i]!='.')
            {
                val1=10*val1+(version1[i]-'0'); 
                i++;
            }
            while(j<version2.size() && version2[j]!='.')
            {
                val2=10*val2+(version2[j]-'0'); 
                j++;
            }

            if(val1!=val2)  // Revisions unequal, return answer
                return(val1>val2?1:-1);
            
            i++,j++;        // Revisions equal, compare further revisions
        }

        return(0);  // Versions are equal     
    }
};

// T.C=O(N) ;   S.C=O(1)
// PATTERN - ATOI