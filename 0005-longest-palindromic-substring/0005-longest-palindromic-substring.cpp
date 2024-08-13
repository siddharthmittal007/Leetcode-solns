class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> dp1(s.size(),1),dp2(s.size(),0);
        pair<int,int> max1={-1,-1},max2={-1,-1};
        
        int l1=-1,r1=-1;
        
        for(int i=0;i<s.size();i++)
        {
            if(i<r1)
            {
                dp1[i]=min(dp1[2*l1-i],r1-i);
            }
            
            while(i-dp1[i]>=0 && i+dp1[i]<s.size() && s[i-dp1[i]]==s[i+dp1[i]])
            {
                dp1[i]++;
            }
            if(max1.second<dp1[i])
            {
                max1={i,dp1[i]};
            }

            if(i+dp1[i]>r1)
            {
                l1=i;
                r1=dp1[i]+i;
            }
        }

        int l2=-1,r2=-1;
        for(int i=0;i<s.size();i++)
        {
            if(i<r2)
            {
                if(2*l2-i>=0)
                dp2[i]=min(dp2[2*l2-i],r2-i-1);

                else
                {
                    dp2[i]=r2-i-1;
                }
            }
            while(i+dp2[i]+1<s.size() && i-dp2[i]>=0 && s[i-dp2[i]]==s[i+dp2[i]+1])
            {
                dp2[i]++;
            }
            if(max2.second<dp2[i])
            {
                max2={i,dp2[i]};
            }
            if(i+dp2[i]+1>r2)
            {
                l2=i;
                r2=i+dp2[i]+1;
            }
        }

        string ans;
        if(max1.second>max2.second)
        {
            cout<<max1.first<<" "<<max1.second;
            ans=s.substr(max1.first-max1.second+1,2*max1.second-1);
        }
        else
        {
            cout<<max2.first<<" "<<max2.second;
            ans=s.substr(max2.first-max2.second+1,2*max2.second);
        }

    return(ans);
    }
};