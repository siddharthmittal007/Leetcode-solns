class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> dp1(s.size(),1);    // Odd length palindromes
        vector<int> dp2(s.size(),0);    // Even length palindromes
        
        pair<int,int> max1={-1,-1};     // Index,palindrome radius pairs(odd pal.)
        pair<int,int> max2={-1,-1};     // Index,palindrome radius pairs(even pal.)
        
        // Finding longest odd length palindrome
        int l1=-1,r1=-1;
        for(int i=0;i<s.size();i++)
        {
            if(i<r1)
                dp1[i]=min(dp1[2*l1-i],r1-i);
 
            while(i-dp1[i]>=0 && i+dp1[i]<s.size() && s[i-dp1[i]]==s[i+dp1[i]])
                dp1[i]++;
            
            if(max1.second<dp1[i])
                max1={i,dp1[i]};

            if(i+dp1[i]>r1)
            {
                l1=i;
                r1=dp1[i]+i;
            }
        }

        // Finding longest even length palindrome
        int l2=-1,r2=-1;
        for(int i=0;i<s.size();i++)
        {
            if(i<r2-1)
                dp2[i]=min(dp2[2*l2-i],r2-i-1);

            while(i+dp2[i]+1<s.size() && i-dp2[i]>=0 && s[i-dp2[i]]==s[i+dp2[i]+1])
                dp2[i]++;
            
            if(max2.second<dp2[i])
                max2={i,dp2[i]};
            
            if(i+dp2[i]+1>r2)
            {
                l2=i;
                r2=i+dp2[i]+1;
            }
        }

        // Finding longest palindrome among odd and even length palindromes
        string ans;
        int mf1=max1.first, ms1=max1.second, mf2=max2.first, ms2=max2.second;
        ans=(ms1>ms2?s.substr(mf1-ms1+1,2*ms1-1):s.substr(mf2-ms2+1,2*ms2));
        
        return(ans);
    }
};

// T,C=O(N) ;   S.C=O(N)
// MY PERSONAL VARIANT OF MANACHERS ALGORTIHM
// PATTERN - TRICK COMMON TO Z-ALGORITHM, KMP 