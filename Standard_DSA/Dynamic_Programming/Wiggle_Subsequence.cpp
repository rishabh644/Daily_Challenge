class Solution {
private:
  int calculate(vector<int>&nums,int index,bool isUp)
  {
      int maxcount=0;


      for(int i=index+1;i<nums.size();i++)
      {

        if( (isUp && nums[i]>nums[index])||(!isUp && nums[i]<nums[index]))
        {
            maxcount=max(maxcount,1+calculate(nums,i,!isUp));

        }



      }

      return maxcount;

  }

public:
    int wiggleMaxLength(vector<int>& nums)
    {

       if(nums.size()<2)
       return nums.size();

       return 1+max(calculate(nums,0,true),calculate(nums,0,false));


    }
};
///////////////////----------------------///////////////////-----------------///////////////////-----------------
class Solution {
private:
  int calculate(vector<int>&nums,int index,bool isUp)
  {
      int maxcount=0;


      for(int i=index+1;i<nums.size();i++)
      {

        if( (isUp && nums[i]>nums[index])||(!isUp && nums[i]<nums[index]))
        {
            maxcount=max(maxcount,1+calculate(nums,i,!isUp));

        }



      }

      return maxcount;

  }

public:
    int wiggleMaxLength(vector<int>& nums)
    {

       if(nums.size()<2)
       return nums.size();

       return 1+max(calculate(nums,0,true),calculate(nums,0,false));


    }
};

//////////////////----------------------/////////////////////////////////-------------------------///////////////////////---------------------///////////////////////////////------------------------//////////////////////----------------------class Solution {
private:
  int calculate(vector<int>&nums,int index,int isUp,vector<vector<int>>&dp)
  {
      int maxcount=0;

      if(dp[index][isUp]!=-1)
      return dp[index][isUp];

      for(int i=index+1;i<nums.size();i++)
      {

        if( (isUp && nums[i]>nums[index])||(!isUp && nums[i]<nums[index]))
        {
            maxcount=max(maxcount,1+calculate(nums,i,!isUp,dp));

        }



      }

      return dp[index][isUp]=maxcount;

  }

public:
    int wiggleMaxLength(vector<int>& nums)
    {

       if(nums.size()<2)
       return nums.size();

       vector<vector<int>>vec(nums.size(),vector<int>(2,-1));

       return 1+max(calculate(nums,0,1,vec),calculate(nums,0,0,vec));


    }
};
/////////////////////////////////////////--------------------------------/////////////////////
class Solution {


public:
    int wiggleMaxLength(vector<int>& nums)
    {

       if(nums.size()<2)
       return nums.size();

       int n=nums.size();

       vector<vector<int>>dp(nums.size(),vector<int>(2,0));

       // dp[i][0]: down, dp[i][1]:up

       int ans=1;

       dp[0][0]=1;
       dp[0][1]=1;

       for(int i=1;i<n;++i)
       {
          for(int j=0;j<i;++j)
          {
             if(nums[i]>nums[j])
             {
                dp[i][1]=max(dp[i][1],dp[j][0]+1); // if nums[i]>nums[j]
                ans=max(ans,dp[i][1]);
             }
             else if(nums[i]<nums[j])
             {
                dp[i][0]=max(dp[i][0],dp[j][1]+1); // if nums[i]<nums[j]
                ans=max(ans,dp[i][0]);
             }
          }

       }


       // The result is the maximum of the last element in eihter up or down state
       return ans;

    }

};
///////////////////////////////
class Solution {


public:
    int wiggleMaxLength(vector<int>& nums)
    {

       if(nums.size()<2)
       return nums.size();

       int n=nums.size();

       vector<int>up(n,0);
       vector<int>down(n,0);

       up[0]=1;
       down[0]=1;

       for(int i=1;i<nums.size();i++)
       {
            if(nums[i]>nums[i-1])
            {
                up[i]=down[i-1]+1;
                down[i]=down[i-1];
            }
            else if(nums[i]<nums[i-1])
            {
                down[i]=up[i-1]+1;
                up[i]=up[i-1];
            }
            else
            {
                down[i]=down[i-1];
                up[i]=up[i-1];
            }
       }

      return max(down[n-1],up[n-1]);
    }

};
/////////////////////////////
class Solution {


public:
    int wiggleMaxLength(vector<int>& nums)
    {

       if(nums.size()<2)
       return nums.size();

       int down=1,up=1;

       for(int i=1;i<nums.size();i++)
       {
             if(nums[i]>nums[i-1])
             {
                up=down+1;
             }
             else if(nums[i]<nums[i-1])
             {
                down=up+1;
             }

       }

       return max(down,up);

    }

};
/////////////////////
