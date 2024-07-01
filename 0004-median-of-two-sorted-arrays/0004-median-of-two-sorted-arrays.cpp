class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();  // Sizes
        
        int low1=-1,low2=-1;                // Lower index bounds on vectors

        int k=(m+n+1)/2;                    // Position of (first)median element

        // Successively halving 'k' at each step (by covering removed half)
        // and increasing lower bounds
        while(k>0)
        {
            int half=k-k/2;
            if(low1==m-1)           // No more elements in 'nums1'
            {
                low2+=half;
                k-=half;
            }
            else if(low2==n-1)      // No more elements in 'nums2'            
            {
                low1+=half;
                k-=half;
            }
            else
            {
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

        if((m+n)%2==1)      // Total number of elements are odd
        {
            if(low1==-1)
            {
                return(nums2[low2]);
            }
            else if(low2==-1)
            {
                return(nums1[low1]);
            }
            else
            {
                return(max(nums1[low1],nums2[low2]));
            }
        }
        else                // Total number of elements are even
        {
            double first,second;
            if(low1==-1)
            {
                first=nums2[low2];
            }
            else if(low2==-1)
            {
                first=nums1[low1];
            }
            else
            {
                first=max(nums1[low1],nums2[low2]);
            }

            low1++;
            low2++;
            if(low1==m)
            {
                second=nums2[low2];
            }
            else if(low2==n)
            {
                second=nums1[low1];
            }
            else
            {
                second=min(nums1[low1],nums2[low2]);
            }

            return((first+second)/2);
        }
    }
};