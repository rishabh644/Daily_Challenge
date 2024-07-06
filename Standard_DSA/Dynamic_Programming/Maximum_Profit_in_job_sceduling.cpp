
bool my_cmp(vector<int>&a, vector<int>&b)
{

    return a[1]<b[1];

}

int findnext(int cur,vector<vector<int>>&jobs)
{   cout<<cur<<endl;
    for(int i=cur+1;i<jobs.size();i++)
    {
        if(jobs[i][0]>=jobs[cur][1])
        return i;
    }

    return -1;
}

int dfs(int i,int n,vector<vector<int>>&jobs,vector<int>&dp)
{
        if(i==n)
        return 0;

        if(dp[i]!=-1)
        return dp[i];

        int next=findnext(i,jobs);

        int inclProf=jobs[i][2] + (next==-1?0:dfs(next,n,jobs,dp));
        int exclProf=dfs(i+1,n,jobs,dp);




        dp[i]=max(inclProf,exclProf);

        return dp[i];
}



class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
          int n=startTime.size();
          vector<vector<int>>jobs(n);
          vector<int>dp(n,-1);
          int i;

          for(i=0;i<n;i++)
          {

              jobs[i]={startTime[i],endTime[i],profit[i]};

          }

          sort(jobs.begin(),jobs.end(),my_cmp);

          return dfs(0,n,jobs,dp);


    }
};

////////////////////--------------------------/////////////////////////
bool mycmp(vector<int>&j1,vector<int>&j2)
{
    if(j1[0]<j2[0])
    return true;
    else if(j1[0]==j2[0] && j1[1]<j2[1])
    return true;
    else if(j1[0]==j2[0] && j1[1]==j2[1] && j1[2]>j2[2])
    return true;
    else
    return false;
}

class Solution {
public:

    int find_index(vector<vector<int>>&jobs,int endtime)
    {

        int i=0;
        int j=jobs.size()-1;

        int ans=j+1;

        while(i<=j)
        {
            int mid=(i+j)/2;

            if(endtime<=jobs[mid][0])
            {
                ans=mid;
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }

        }

        return ans;
    }
    int job_schedule(vector<vector<int>>&jobs,vector<int>&mxm,int i,int n)
    {
        if(i==n)
        return 0;

        if(mxm[i]!=-1)
        return mxm[i];


        int sp,tp;

        //skip

        sp=job_schedule(jobs,mxm,i+1,n);

        //take
        int ind=find_index(jobs,jobs[i][1]);
        tp=jobs[i][2]+job_schedule(jobs,mxm,ind,n);

        mxm[i]=max(sp,tp);

        return mxm[i];

    }


    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

     int n=startTime.size();
     vector<vector<int>>jobs;

     int i=0;

     while(i<n)
     {
        jobs.push_back({startTime[i],endTime[i],profit[i]});
        i++;
     }

     sort(jobs.begin(),jobs.end(),mycmp);

     vector<int>mxm(n,-1);

     job_schedule(jobs,mxm,0,n);

     return mxm[0];



    }
};
////////////////--------------------------/////////////////////////
////////////////////-------------------------------/////////////////////////
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n=startTime.size();
        vector<vector<int>>jobs;

        for(int i=0;i<n;++i)
        {
            jobs.push_back({endTime[i],startTime[i],profit[i]});
        }

        sort(jobs.begin(),jobs.end());

        map<int,int>dp={{0,0}};

        for(auto& job:jobs) {

           int cur=prev(dp.upper_bound(job[1]))->second+job[2];

           if( cur>dp.rbegin()->second)
               dp[job[0]]=cur;

        }

        return dp.rbegin()->second;

    }
/////////////////////////////////////---------------------------------------////////////////////////////////////////////
class Solution {
public:

    static bool my_cmp(vector<int>&j1,vector<int>&j2)
    {
        return j1[0]<j2[0];
    }

    int find_index(vector<vector<int>>&jobs,int endtime)
    {

        int i=0;
        int j=jobs.size()-1;

        int ans=j+1;

        while(i<=j)
        {
            int mid=(i+j)/2;

            if(endtime<=jobs[mid][0])
            {
                ans=mid;
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }

        }

        return ans;
    }



    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n=startTime.size();
        vector<vector<int>>jobs;

        for(int i=0;i<n;++i)
        {
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }

        sort(jobs.begin(),jobs.end(),my_cmp);

       // map<int,int>dp={{0,0}};

        vector<int>dp(n);

        dp[n-1]=jobs[n-1][2];

        for(int j=n-2;j>=0;j--){

        int next=find_index(jobs,jobs[j][1]);

        dp[j]=max(jobs[j][2]+(next==n?0:dp[next]),dp[j+1]);

                              }

        return dp[0];


    }
};
