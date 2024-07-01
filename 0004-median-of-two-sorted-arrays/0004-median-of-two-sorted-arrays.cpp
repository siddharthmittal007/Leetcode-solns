class Solution {
public:
    double solve(vector<int>& nums1,int low1,vector<int>& nums2,int low2,int k)
    {   
        int m=nums1.size(),n=nums2.size();  // Sizes
        
        if(low1==m || low2==n)
        {
            return(low1==m?nums2[low2+k-1]:nums1[low1+k-1]);
        }
        else
        {
            if(k==1)
            {
                return(nums1[low1]<=nums2[low2]?nums1[low1]:nums2[low2]);
            }
            int half=k/2;
            int ind1=min(m-1,low1+half-1);
            int ind2=min(n-1,low2+half-1);

            if(nums1[ind1]<=nums2[ind2])
            {
                k-=ind1-low1+1;
                return(solve(nums1,ind1+1,nums2,low2,k));
            }
            else
            {
                k-=ind2-low2+1;
                return(solve(nums1,low1,nums2,ind2+1,k));
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();  // Sizes
    
        int k=(m+n+1)/2;                    // Position of(first)median element

        if((m+n)%2==1)                      // Odd number of elements
        {
            return(solve(nums1,0,nums2,0,k));
        }
        else                                // Even number of elements                                                
        {
            return((solve(nums1,0,nums2,0,k)+solve(nums1,0,nums2,0,k+1))/2);
        }
    }
};