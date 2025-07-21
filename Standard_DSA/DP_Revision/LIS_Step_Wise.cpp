class Solution {
public:

    void max_length(vector<int>& nums,int last,int i,int cl,int& ans)
    {

       if(i==nums.size())
       {
        ans=max(ans,cl);
        return;
       }

       // don take
       max_length(nums,last,i+1,cl,ans);
       //take
       if(nums[i]>last)
       max_length(nums,nums[i],i+1,cl+1,ans);

    }

    int lengthOfLIS(vector<int>& nums)
    {

        int ans=0;

        int last=-10001;

        int i=0;
        int cl=0;
        max_length(nums,last,i,cl,ans);

        return ans;

    }
};

///////////////////////////////////////
class Solution {

    vector<vector<int>>dp;
public:

    int  max_length(vector<int>& nums,int last,int i)
    {

       if(i==nums.size())
       {
        return 0;
       }

       if(dp[last+1][i]!=-1)
       return dp[last+1][i];

       // don take
       int dont_take=0;
       dont_take=max_length(nums,last,i+1);

       //take
       int take=0;
       if(last==-1 || nums[i]>nums[last])
       take=1+max_length(nums,i,i+1);

       dp[last+1][i]=max(dont_take,take);

       return dp[last+1][i];

    }

    int lengthOfLIS(vector<int>& nums)
    {
        int ans=0;
        int last=-1;
        int n=nums.size();
        dp=vector<vector<int>>(n+1,vector<int>(n,-1));
        int i=0;
        ans=max_length(nums,last,i);
        return ans;
    }
};
////////////////////////////////////////////////////////////
