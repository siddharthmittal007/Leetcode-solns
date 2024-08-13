class Solution {
public:
    string longestPalindrome(string s) {
        // Ensuring all palindromes to be of odd length
        string s_prime="#";
        for(int i=0;i<s.size();i++)
        {
            s_prime+=s[i];
            s_prime+='#';
        }

        vector<int> radii(s_prime.size(),0);    // Palindrome radii
        
        // Finding palindrome radii for each index
        int center =0,radius=0;
        for(int i=0;i<s_prime.size();i++)
        {
            int mirror=2*center-i;
            if(i<radius)
                radii[i]=min(radii[mirror],radius-i);

            while(i-radii[i]-1>=0 && i+radii[i]+1<s_prime.size() && 
                    s_prime[i-radii[i]-1]==s_prime[i+radii[i]+1])
            {
                radii[i]++;
            }

            if(i+radii[i]>radius)
            {
                center=i;
                radius=radii[i]+i;
            }
        }

        // Finding max palindrome length and center
        int max_center=0,max_length=0;
        for(int i=0;i<radii.size();i++)
        {
            if(max_length<radii[i])
            {
                max_center=i;
                max_length=radii[i];
            }
        }

        int start_index=(max_center-max_length)/2;

        return(s.substr(start_index,max_length));
    }
};

// T,C=O(N) ;   S.C=O(N)
// MANACHERS ALGORITHM
// PATTERN - TRICK COMMON TO Z-ALGORITHM, KMP 
