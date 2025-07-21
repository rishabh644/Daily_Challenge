bool mycheck(vector<int>&nums,int i,int& s1,int& s2)
    {

          if(i==nums.size())
          {

            if(s1==s2)
            return true;
            else
            return false;

          }

          // take into s1

          s1+=nums[i];

          bool s_1=mycheck(nums,i+1,s1,s2);

          s1-=nums[i];
          s2+=nums[i];
          bool s_2=mycheck(nums,i+1,s1,s2);
          s2-=nums[i];


          return s_1|s_2;
    }

    bool canPartition(vector<int>& nums)
    {

       int totalSum=0;

       for(int num:nums)
       {
        totalSum+=num;
       }

       if(totalSum%2!=0)
       return false;

       int subSetSum=totalSum/2;

       int n=nums.size();

       vector<vector<bool>>dp(n+1,vector<bool>(subSetSum+1,false));

       dp[0][0]=true;

       for(int i=1;i<=n;i++)
       {
          int curr=nums[i-1];
          for(int j=0;j<=subSetSum;j++)
          {
            if(j<curr)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=(dp[i-1][j]) ||(dp[i-1][j-curr]);
            }
          }
       }

       return dp[n][subSetSum];

    }