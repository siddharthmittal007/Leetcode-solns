class Solution {
public:
    int solve(vector<int>& nums1,vector<int>& nums2,int k)
    {   
        int m=nums1.size(),n=nums2.size();  // Sizes
        
        int low=0,high=m-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int FL=mid;
            int FR=FL+1;
            int SL=k-mid-2;
            int SR=SL+1;

            if(SL>=n)
            {
                low=mid+1;
            }
            else if(SL<0)
            {
                if(n!=0 && nums2[0]<nums1[FL])
                high=mid-1;
                else
                {
                    return(nums1[FL]);
                }
            }
            else if ((SR==n || nums1[FL]<=nums2[SR]) &&
                    (FR==m || nums2[SL]<=nums1[FR]))
            {
                return(max(nums1[FL],nums2[SL]));   // Element found
            }
            else if(SR!=n && nums1[FL]>nums2[SR])
            {
                high=mid-1;
            }
            else    //(FR!=m && nums2[SL]>nums1[FR])
            {
                low=mid+1;
            }
            
        }  
        return(nums2[k-1]); 
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensuring 'nums1' of lesser(or equal) size to 'nums2'
        if(nums1.size()>nums2.size())
        {
            return(findMedianSortedArrays(nums2,nums1));
        }
        
        int m=nums1.size(),n=nums2.size();  // Sizes
    
        int k=(m+n+1)/2;                    // Position of(first)median element

        if((m+n)%2==1)                      // Odd number of elements
        {
            return(1.0*solve(nums1,nums2,k));
        }
        else                                // Even number of elements                                                
        {
            return((1.0*(solve(nums1,nums2,k)+solve(nums1,nums2,k+1)))/2);
        }
    }
};