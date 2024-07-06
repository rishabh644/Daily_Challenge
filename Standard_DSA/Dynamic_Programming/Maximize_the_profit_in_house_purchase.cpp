

bool mycmp(vector<int>&a,vector<int>&b)
{
     if(a[0]<b[0])
         return true;
     else
         return false;
}


int binary_search(vector<vector<int>>&offers,int k,int low,int high)
{   int mid;
    int next_pos=offers.size();
    while(low<=high)
    {
        int mid=(low+high)/2;

        if(offers[mid][0]>k)
        {
              high=mid-1;
              next_pos=mid;
        }
        else
        {
            low=mid+1;
        }


    }
    return next_pos;
}


int mymaximizeprofit(vector<vector<int>>&offers,int i,vector<int>&dp)
{       int takeof,nottakeof,next_pos;
        if(i==offers.size())
        {
               return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        nottakeof=mymaximizeprofit(offers,i+1,dp);
        next_pos=binary_search(offers,offers[i][1],i+1,offers.size()-1);
        takeof=offers[i][2]+mymaximizeprofit(offers,next_pos,dp);


        dp[i]=max(takeof,nottakeof);
        return dp[i];

}

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {


        sort(offers.begin(),offers.end(),mycmp);
        vector<int>dp(offers.size(),-1);

        return mymaximizeprofit(offers,0,dp);

    }
};
////////////////////////-------------------------/////////////////////////////

class Solution {
public:

   static  bool cmp(vector<int>&o1,vector<int>&o2)
    {
        return o1[0]<o2[0];
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {

        vector<vector<int>>my_offers;

        for(auto v:offers)
        {
            my_offers.push_back({v[1],v[0],v[2]});
        }

        sort(my_offers.begin(),my_offers.end(),cmp);

        map<int,int>mp;
        int i=0;

        mp[-1]=0;

        while(i<my_offers.size())
        {
            int prev_prof=prev(mp.lower_bound(my_offers[i][1]))->second;
            int prof;
            prof=prev_prof+my_offers[i][2];

            if((mp.rbegin()->second)<prof)
            {
                mp[my_offers[i][0]]=prof;
            }

            i+=1;
        }


        return mp.rbegin()->second;


    }
};

///////////////////////////---------------------/////////////////////////////
class Solution {
public:

   static  bool cmp(vector<int>&o1,vector<int>&o2)
    {
        return o1[0]<o2[0];
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {

        vector<vector<int>>my_offers;

        for(auto v:offers)
        {
            my_offers.push_back({v[1],v[0],v[2]});
        }

        sort(my_offers.begin(),my_offers.end(),cmp);

        map<int,int>mp;
        int i=0;

        mp[-1]=0;

        while(i<my_offers.size())
        {
            int prev_prof=prev(mp.lower_bound(my_offers[i][1]))->second;
            int prof;
            prof=prev_prof+my_offers[i][2];

            if((mp.rbegin()->second)<prof)
            {
                mp[my_offers[i][0]]=prof;
            }

            i+=1;
        }


        return mp.rbegin()->second;


    }
};
///////////////////////////////////////-----------------------------------///////////////////////////////////////
class Solution {
public:



    int maximizeTheProfit(int n, vector<vector<int>>& offers) {

        vector<int>dp(n+1);

        vector<vector<vector<int>>>m(n);

        for(auto&a :offers){
            m[a[1]].push_back(a);
        }

        for(int e=1;e<=n;e++)
        {
            dp[e]=dp[e-1];

            for(auto& a:m[e-1]){
                dp[e]=max(dp[e],dp[a[0]]+a[2]);
            }

        }

        return dp[n];

    }
};
/////////////////////////////////////////////////--------------------------//////////////////////