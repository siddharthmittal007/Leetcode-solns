class Solution {
public:

    void quickselect(vector<int> &v,int low,int high,int k)
    {
        // Lomuto partition
        int pivot=v[high];
        int j=low-1;
        for(int i=low;i<high;i++)
        {
            if(v[i]>pivot)
            {
                j++;
                swap(v[j],v[i]);
            }
        }
        j++;
        swap(v[j],v[high]);

        // Quickselect D&C
        if(k-1==j)
        {
            return;
        }
        else if(k-1<j)
        {
            quickselect(v,low,j-1,k);
        }
        else
        {
            quickselect(v,j+1,high,k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        quickselect(nums,0,nums.size()-1,k);
        return(nums[k-1]);// Return 'k'th largest element
    }
};
