class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Binary search
        int low=0,high=nums.size()-1;

        while(low<high)
        {
            int mid=low+(high-low)/2;

            if(mid%2==1)
            {
                mid--;      // Making 'mid' always even 
            }

            if(nums[mid]==nums[mid+1])
            {
                low=mid+2;  // Element in second half
            }
            else
            {
                high=mid;   // Element in first half
            }
        }

        return(nums[low]);     
        
    }
};
