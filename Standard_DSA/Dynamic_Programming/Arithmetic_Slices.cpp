// Number of sub_arrays_in_AP_size_at_least_three
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {

     int ans=0;
     int n=nums.size();
     int diff;
     for(int i=0;i<=n-3;i++)
     {
        diff=nums[i+1]-nums[i];
        for(int j=i+2;j<n;j++)
        {
            if( (nums[j]-nums[j-1])==diff )
            {
                ans+=1;
            }
            else
            {
                break;
            }
        }

     }

     return ans;

    }
};
///////////////////////////
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
     int ans=0;
     int n=nums.size();
     if(n<3)
     return 0;
     int diff;
     int pvdiff=nums[n-1]-nums[n-2];
     vector<int>dp(n,0);

     for(int i=n-3;i>=0;i--)
     {
        diff=nums[i+1]-nums[i];
        if(pvdiff==diff)
        {
            dp[i]=1+dp[i+1];
            ans+=dp[i];
        }
        pvdiff=diff;
     }

     return ans;

    }
};