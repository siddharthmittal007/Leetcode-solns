class Solution {
public:
    string ans;
    int factorial(int n) 
    {
        if (n == 0) 
        {
            return (1);
        }
        return (n * factorial(n - 1));
    }
    void permutationSequence(int n,int fact, int k, vector<char>& nums) {
        if (n == 1) 
        {
            ans.push_back(nums[0]);
            return;
        }

        int q = (k - 1) / fact;
        int r = ((k-1) % fact) + 1;

        ans.push_back(nums[q]);
        nums.erase(nums.begin()+q);
        fact=fact/(n-1);
        permutationSequence(n-1,fact,r,nums);
    }
    string getPermutation(int n, int k) {
        vector<char> nums;
        for(int i=1;i<=n;i++)
        {
            nums.push_back('1'+(i-1));
        }
        int fact;
        fact=factorial(n-1);
        permutationSequence(n,fact,k,nums);
        return(ans);
    }
};