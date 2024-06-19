class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums,vector<int>& v,vector<bool>& flag)
    {
        // Base Case(saving solution)
        if(v.size()==nums.size())
        {
            ans.push_back(v);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(flag[i]==false) // Number status='Unused'
            {
                v.push_back(nums[i]);
                flag[i]=true;

                backtrack(nums,v,flag);

                v.pop_back();
                flag[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> flag(nums.size(),false);   // To store status(Used/Unused)
                                                // of number
        
        vector<int> v;                          // To store permutations
        
        backtrack(nums,v,flag);
        return(ans);
    }
};