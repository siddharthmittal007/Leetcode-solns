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
        int center =-1,radius=-1;
        for(int i=0;i<s_prime.size();i++)
        {
            if(i<=center+radius)
                radii[i]=min(radii[center-radius],center+radius-i+1);

            while(i-radii[i]-1>=0 && i+radii[i]+1<s_prime.size() && 
                    s_prime[i-radii[i]-1]==s_prime[i+radii[i]+1])
            {
                radii[i]++;
            }

            if(i+radii[i]>center+radius)
            {
                center=i;
                radius=radii[i];
            }
        }

        // Finding max palindrome radii and center
        int max_center=-1,max_radius=-1;
        for(int i=0;i<radii.size();i++)
        {
            if(max_radius<radii[i])
            {
                max_center=i;
                max_radius=radii[i];
            }
        }

        int start_index=(max_center-max_radius)/2;
        int length=max_radius;

        return(s.substr(start_index,max_radius));
    }
};

// T,C=O(N) ;   S.C=O(N)
// MANACHERS ALGORITHM
// PATTERN - TRICK COMMON TO Z-ALGORITHM, KMP 