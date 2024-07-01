class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int k) {
        int m=nums1.size(),n=nums2.size();  // Sizes
        
        int low1=-1,low2=-1;                // Lower index bounds on vectors

        // Successively halving 'k' at each step (by covering removed half)
        // and increasing lower bounds
        while(k>0)
        { 
            if(low1==m-1)           // No more elements in 'nums1'
            {
                low2+=k;
                k=0;
            }
            else if(low2==n-1)      // No more elements in 'nums2'            
            {
                low1+=k;
                k=0;
            }
            else
            {
                int half=k-k/2;

                int ind1=min(m-1,low1+half);
                int ind2=min(n-1,low2+half);
                
                if(nums1[ind1]<=nums2[ind2])    
                {
                    k-=ind1-low1;
                    low1=ind1;
                }
                else
                {
                    k-=ind2-low2;
                    low2=ind2;
                }
            }
        }

        if(low1==-1 || low2==-1)
        {
            return(low1==-1?nums2[low2]:nums1[low1]);
        }
        else
        {
            return(max(nums1[low1],nums2[low2]));
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();  // Sizes

        int k=(m+n+1)/2;                    // Position of (first)median element

        if((m+n)%2==1)
        {
            return(1.0*solve(nums1,nums2,k));
        }
        else
        {
            return((1.0*(solve(nums1,nums2,k)+solve(nums1,nums2,k+1)))/2);
        }
    }
};