class Solution {
public:
    struct T
    {
        double max_val,min_val;
        string min_str,max_str;
        T()
        {
            max_val=-1;
        }
    };

    string optimalDivision(vector<int>&nums)
    {
        vector<vector<T>>dp(nums.size(),vector<T>(nums.size()));
        T t=optimal(nums,0,nums.size()-1,dp);
        return t.max_str;
    }

    T optimal(const vector<int>&nums,int start,int end,vector<vector<T>>&dp)
    {
        T t;

        if(start==end)
        {
            t.max_val=nums[start];
            t.min_val=nums[start];
            t.min_str=to_string(nums[start]);
            t.max_str=to_string(nums[start]);
            return t;
        }

        if(dp[start][end].max_val!=-1)
        return dp[start][end];

        t.min_val=numeric_limits<double>::max();
        t.max_val=numeric_limits<double>::lowest();

        for(int i=start;i<end;i++)
        {

          T left=optimal(nums,start,i,dp);
          T right=optimal(nums,i+1,end,dp);

          if(t.min_val>(left.min_val/right.max_val) )
          {
             t.min_val=left.min_val/right.max_val;
             t.min_str=left.min_str+"/" +(i+1!=end?"(":"")+right.max_str+(i+1!=end?")":"");

          }

          if(t.max_val<left.max_val/right.min_val)
          {
            t.max_val=left.max_val/right.min_val;
            t.max_str=left.max_str+"/"+(i+1!=end?"(":"")+right.min_str+(i+1!=end?")":"");
          }


        }

        return dp[start][end]=t;
    }

};