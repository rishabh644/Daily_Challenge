class Solution{

private:
    vector<vector<int>>dp;


public:

    int maxmprof(int i,int n,int w,int val[],int wt[])
    {

       if(i==n)
       return 0;

       if(dp[i][w]!=-1)
       return dp[i][w];

       int nottake=0,take=0;

       nottake=maxmprof(i+1,n,w,val,wt);

       if(w>=wt[i])
       take=val[i]+maxmprof(i,n,w-wt[i],val,wt);

       return dp[i][w]=max(nottake,take);
    }


    int knapSack(int N, int W, int val[], int wt[])
    {

       dp=vector<vector<int>>(N,vector<int>(W+1,-1));

       return maxmprof(0,N,W,val,wt);



    }
};

///////////////////////////////////////////////////////////////////------------------------------------------------------//////////////////////////////////////////////////////////////


class Solution{
private:
    vector<vector<int>>dp;
public:
    int knapSack(int N, int W, int val[], int wt[])
    {

       dp=vector< vector<int> >( N+1 , vector<int>(W+1,0) );

       // dp[i][j] how much profit you can make by upto i item and utilizing j weight

       for(int i=1;i<=N;i++)
       {
           int cw=wt[i-1];

           for(int j=0;j<=W;j++)
           {
               if(j<cw)
               dp[i][j]=dp[i-1][j];
               else
               dp[i][j]=max(dp[i-1][j],dp[i][j-cw]+val[i-1]);
           }

       }


        return dp[N][W];

    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////----------------------------------------------------//////////////////////////////////////////////////////////////////////////