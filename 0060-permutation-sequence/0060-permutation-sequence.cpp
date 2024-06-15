class Solution {
public:
    string ans;
    int fact(int n) 
    {
        if (n == 0) 
        {
            return (1);
        }
        return (n * fact(n - 1));
    }
    void permutationSequence(int n, int k, vector<char>& nums) {
        if (n == 0) 
        {
            return;
        }

        int q = (k - 1) / fact(n-1);
        int r = ((k-1) % fact(n-1)) + 1;

        ans.push_back(nums[q]);
        nums.erase(nums.begin()+q);
        permutationSequence(n-1,r,nums);
    }
    string getPermutation(int n, int k) {
        vector<char> nums;
        for(int i=1;i<=n;i++)
        {
            nums.push_back('1'+(i-1));
        }

        permutationSequence(n,k,nums);
        return(ans);
    }
};