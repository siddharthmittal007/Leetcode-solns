class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Binary search
        int low=0,high=nums.size()-1;

        while(low<high)
        {
            int mid=low+(high-low)/2;

            if  ((mid-low)%2==0 && nums[mid]==nums[mid-1])
            {
                high=mid-2;         // Element in first half
            }
            else if((mid-low)%2==1 && nums[mid]==nums[mid+1])
            {
                high=mid-1;         // Element in first half
            }
            else if ((mid-low)%2==0 && nums[mid]==nums[mid+1])
            {
                low=mid+2;          // Element in second half
            }
            else if((mid-low)%2==1 && nums[mid]==nums[mid-1])
            {
                low=mid+1;          // Element in second half
            }
            else
            {
                return(nums[mid]);   // Element found
            }
        }

        return(nums[low]);          // Element found
        
    }
};
