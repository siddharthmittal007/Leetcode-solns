class Solution {
public:
    vector<vector<int>> ans; // To store answer permutations

    void backtrack(vector<int>& nums, int index) 
    {
        // Base Case(saving solution)
        if (index == nums.size()) 
        {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) 
        {
            swap(nums[i],nums[index]);
            backtrack(nums,index+1);
            swap(nums[i],nums[index]);
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums,0);
        return (ans);
    }
};