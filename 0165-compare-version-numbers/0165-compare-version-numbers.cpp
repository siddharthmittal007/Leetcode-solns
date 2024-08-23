class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        while(i<version1.size() || j<version2.size())
        {
            int val1=0,val2=0;
            while(i<version1.size() && version1[i]!='.')
            {
                val1=10*val1+version1[i]-'0';
                cout<<val1<<" ";
                i++;
            }
            while(j<version2.size() && version2[j]!='.')
            {
                val2=10*val2+version2[j]-'0';
                cout<<val2<<" ";
                j++;
            }

            if(val1!=val2)
                return(val1>val2?1:-1);
            i++,j++;
        }

        return(0);       
    }
};