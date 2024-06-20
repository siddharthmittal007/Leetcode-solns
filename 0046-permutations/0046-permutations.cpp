class Solution {
public:
    vector<vector<int>> ans; // To store answer permutations
    
    void backtrack(vector<int>& nums, int index, vector<int>& v) 
    {
        // Base Case(saving solution)
        if (index == nums.size()) 
        {
            ans.push_back(v);
            return;
        }

        for (int i = index; i < nums.size(); i++) 
        {
            v.push_back(nums[i]);
            swap(nums[i],nums[index]);

            backtrack(nums,index+1,v);

            v.pop_back();
            swap(nums[i],nums[index]);
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;              // To store permutations
        backtrack(nums,0,v);
        return (ans);
    }
};