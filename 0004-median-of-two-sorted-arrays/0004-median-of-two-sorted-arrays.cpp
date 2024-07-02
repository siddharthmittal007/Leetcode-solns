class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensuring 'nums1' of lesser(or equal) size to 'nums2'
        if(nums1.size()>nums2.size())
        {
            return(findMedianSortedArrays(nums2,nums1));
        }
        
        int m=nums1.size(),n=nums2.size();  // Sizes
    
        int k=(m+n+1)/2;                    // Position of(first)median element

        // Binary search
        int low=0,high=m;
        while(low<=high)
        {
            int partitionA=low+(high-low)/2;
            int partitionB=k-partitionA;

            int LeftA=(partitionA==0?INT_MIN:nums1[partitionA-1]);
            int RightA=(partitionA==m?INT_MAX:nums1[partitionA]);
            int LeftB=(partitionB==0?INT_MIN:nums2[partitionB-1]);
            int RightB=(partitionB==n?INT_MAX:nums2[partitionB]);

            if(LeftA<=RightB && LeftB<=RightA)
            {
                // Median element(s) found
                if((m+n)%2==1)      // Single median
                {
                    return(max(LeftA,LeftB));
                }
                else                // Two medians
                {
                    return  ((1.0*(max(LeftA,LeftB)+
                            min(RightA,RightB)))/2);
                }
            }
            else if(LeftA>RightB)
            {
                high=partitionA-1;
            }
            else    // (LeftB>RightA)
            {
                low=partitionA+1;
            }        
        } 

        return(0); 
    }
};