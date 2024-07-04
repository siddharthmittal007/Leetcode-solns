class Solution {
public:
    int solve(vector<int>& nums1,int low1,int high1,vector<int>& nums2,int low2,int high2,int k)
    {   
        if(low1>high1)      // 'nums1' empty
        {
            return(nums2[k-low1-1]);
        }
        else if(low2>high2) // 'nums2' empty
        {
            return(nums1[k-low2-1]);
        }
        else                // 'nums1' and 'nums2' non-empty
        {
            int mid1=low1+(high1-low1)/2;
            int mid2=low2+(high2-low2)/2;
            int count=(mid1+1)+(mid2+1);

            if(count<=k)        // Eliminate first half
            {
                if(nums1[mid1]<=nums2[mid2])        
                {
                    // Eliminate first half of 'nums1'
                    return(solve(nums1,mid1+1,high1,nums2,low2,high2,k));
                }
                else
                {
                    // Eliminate first half of 'nums2'
                    return(solve(nums1,low1,high1,nums2,mid2+1,high2,k));
                }
            }
            else                // Eliminate second half
            {
                if(nums1[mid1]<=nums2[mid2])
                {
                    // Eliminate second half of 'nums2'
                    return(solve(nums1,low1,high1,nums2,low2,mid2-1,k));
                }
                else
                {
                    // Eliminate second half of 'nums1'
                    return(solve(nums1,low1,mid1-1,nums2,low2,high2,k));
                }
            }
        }       
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();  // Sizes
    
        int k=(m+n+1)/2;                    // Position of(first)median element

        if((m+n)%2==1)                      // Odd number of elements
        {
            return(1.0*solve(nums1,0,m-1,nums2,0,n-1,k));
        }
        else                                // Even number of elements                                                
        {
            return((1.0*(solve(nums1,0,m-1,nums2,0,n-1,k)+solve(nums1,0,m-1,nums2,0,n-1,k+1)))/2);
        }
    }
};