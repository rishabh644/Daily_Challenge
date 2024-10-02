class Solution {
public:

    unordered_map<int,int>mark;

    int dp[2001][2001];

    int solve(vector<int>&stones,int n,int index,int prevJump)
    {
        //If reached the last stone, return 1
        if(index==n-1)
        return 1;

        //If this subproblem has been already calculated, return it.

        if(dp[index][prevJump]!=-1)
        {
            return dp[index][prevJump];
        }

        int ans=false;

        // Iterate over the three possibilities {k-1,k,k+1}

        for(int nextJump=prevJump-1;nextJump<=prevJump+1;nextJump++)
        {
            if(nextJump>0 && mark.find(stones[index]+nextJump)!=mark.end())
            {
                ans=ans || solve(stones,n,mark[stones[index]+nextJump],nextJump);
            }
        }


        // Store the result to fetch later

        return dp[index][prevJump]=ans;

    }

    bool canCross(vector<int>& stones)
    {

       int n=stones.size();

       // Mark stones in the map to identify id such stone exists or not

       for(int i=0;i<stones.size();i++)
       {
         mark.insert({stones[i],i});
       }

       // Mark all states as -1 to denote they're not calculated

       memset(dp,-1,sizeof(dp));

       return solve(stones,stones.size(),0,0);

    }
};
////////////////////////////////////////
class Solution {
public:

    unordered_map<int,int>mark;

    int dp[2001][2001];

    int solve(vector<int>&stones,int n,int index,int prevJump)
    {
        //If reached the last stone, return 1
        if(index==n-1)
        return 1;

        //If this subproblem has been already calculated, return it.

        if(dp[index][prevJump]!=-1)
        {
            return dp[index][prevJump];
        }

        int ans=false;

        // Iterate over the three possibilities {k-1,k,k+1}

        for(int nextJump=prevJump-1;nextJump<=prevJump+1;nextJump++)
        {
            if(nextJump>0 && mark.find(stones[index]+nextJump)!=mark.end())
            {
                ans=ans || solve(stones,n,mark[stones[index]+nextJump],nextJump);
            }
        }


        // Store the result to fetch later

        return dp[index][prevJump]=ans;

    }

    bool canCross(vector<int>& stones)
    {

       int n=stones.size();

       // Mark stones in the map to identify id such stone exists or not

       for(int i=0;i<stones.size();i++)
       {
         mark.insert({stones[i],i});
       }

       // Mark all states as -1 to denote they're not calculated

       dp[0][0]=1;

       for(int index=0;index<n;index++)
       {

          for(int prevJump=0;prevJump<=n;prevJump++)
          {
               // If stone exists, mark the value with position and jump as 1

               if(dp[index][prevJump])
               {
                  if(mark[stones[index]+prevJump])
                  {
                    dp[mark[stones[index] + prevJump]][prevJump]=1;
                  }

                  if(mark[stones[index]+prevJump+1])
                  {
                    dp[mark[stones[index]+prevJump+1]][prevJump+1]=1;
                  }

                  if(mark[stones[index]+prevJump-1])
                  {
                    dp[mark[stones[index]+prevJump-1]][prevJump-1]=1;
                  }

               }

          }

       }

       // if any value with index as n-1 id true, return true;

       for(int prevJump=0;prevJump<=n;prevJump++)
       {
         if(dp[n-1][prevJump])
         return true;
       }

       return false;

    }
};