class Solution {
public:

    void quickselect(vector<int> &v,int low,int high,int k)
    {
        if(low==high)
        {
            return;     //kth largest in position
        }
        
        // Chooosing random pivot
        int pivot_index=low+rand()%(high-low+1);
        swap(v[pivot_index],v[low]);

        // Hoare partition
        int pivot=v[low];
        int i=low-1,j=high+1;
        while(true)
        {
            while(v[++i]>pivot);
            while(v[--j]<pivot);
            if(i>=j)
            {
                break;
            }
            swap(v[i],v[j]);

            if(k<=j+1)
            {
                quickselect(v,low,j,k);
            }
            else
            {
                quickselect(v,j+1,high,k);
            }      
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        quickselect(nums,0,nums.size()-1,k);
        return(nums[k-1]);  // Return 'k'th largest element
    }
};
