class Solution {
public:
    int findPivot(vector<int>& nums)
    {
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[low]<=nums[high])
            {
                return(low);    // Pivot at 'low'
            }
            else if(nums[low]<=nums[mid])
            {
                low=mid+1;      // Pivot in second half
            }
            else    
            {
                high=mid;       // Pivot in first half
            }
        }

        return(0);              // Dummy return
    }

    int search(vector<int>& nums, int target) {
        int pivot=findPivot(nums);
        
        int index;
        if(pivot!=0 && target>=nums[0]) // 'target' in first segment
        {
            index   =lower_bound(nums.begin(),nums.begin()+pivot,target)
                    -nums.begin();
        }
        else                            // 'target' in second segment
        {
            index   =lower_bound(nums.begin()+pivot,nums.end(),target)
                    -nums.begin();
        }

        if(index==nums.size() || nums[index]!=target)
        {
            return(-1);                 // 'target' not found
        }
        else
        {
            return(index);              // 'target' found at 'index'
        }
        
    }
};