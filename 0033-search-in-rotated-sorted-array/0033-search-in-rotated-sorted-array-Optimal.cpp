class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Binary search
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(nums[mid]==target)
            {
                return(mid);    // 'target' found
            }

            else if(nums[low]<=nums[mid])   // First half sorted
            {
                if(target>=nums[low] && target<nums[mid])
                {
                    high=mid-1;    
                }
                else 
                {
                    low=mid+1;      
                } 
            }
            
            else    // (nums[mid]<nums[low]) i.e. Second half sorted
            {
                if(target<=nums[high] && target>nums[mid])
                {
                    low=mid+1;
                }
                else   
                {
                    high=mid-1;
                }
            }
        }

        return(-1);     // 'target' not found

        
    }
};
