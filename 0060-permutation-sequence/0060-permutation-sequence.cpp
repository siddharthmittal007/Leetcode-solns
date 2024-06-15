class Solution {
public:
    // Vector of numbers (1 to n)
    vector<int> nums;
    // Vector storing factorials
    vector <int> factorials;

    void permutationSequence(int n, int k, string& ans) {
        // Base case
        if (n == 0) 
        {
            return;
        }

        int index = (k - 1) / factorials[n-1];      // Index of digit at current
                                                    // place in sequence
        int new_k = ((k-1) % factorials[n-1]) + 1;  // Value of k for subsequence
                                                    // of (n-1) digits

        ans.push_back('0'+nums[index]); // adding current digit to string
        nums.erase(nums.begin()+index); // Deleting digit from stored numbers   
        
        permutationSequence(n-1,new_k,ans);   // evalauting subsequence of 
                                                // (n-1) digits
    }
    string getPermutation(int n, int k) {
        // Initializing vector of numbers (1 to n)
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }

        // Intializing vector storing factorials
        int fact=1;
        factorials.push_back(fact);
        for(int i=1;i<n;i++)
        {
            fact*=i;
            factorials.push_back(fact);
        }
        
        string ans;
        permutationSequence(n,k,ans);
        return(ans);
    }
};