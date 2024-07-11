class Solution {
public:

    void quickselect(vector<pair<int,int>> &v,int low,int high,int k)
    {
        // Lomuto partition
        pair<int,int> pivot=v[high];
        int j=low-1;
        for(int i=low;i<high;i++)
        {
            if(v[i].second>pivot.second)
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Inserting elements to unordered map 
        // and maintaining frequency count of element
        unordered_map<int,int> ump;
        for(int i=0;i<nums.size();i++)
        {
            if(ump.find(nums[i])==ump.end())
            {
                ump.insert({nums[i],1});
            }
            else
            {
                ump.at(nums[i])++;
            }
        }

        // Obtaining 'k' most frequent elements using
        // Quickselect
        vector<pair<int,int>> v(ump.begin(),ump.end());
        quickselect(v,0,v.size()-1,k);

        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].first);
        }
        
        return(ans);// Return 'k' most frequent elements
        
    }
};

// T.C=O(N^2)-WORST CASE,O(N)-AVG CASE  ;   S.C=O(N)-WORST CASE,O(LOGN)-AVG CASE