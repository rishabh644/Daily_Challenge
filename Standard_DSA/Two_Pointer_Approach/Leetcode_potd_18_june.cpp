bool cmp(pair<int,int>a,pair<int,int>b)
{
   if(a.first==b.first)
   return a.second>b.second;
   else
   return a.first<b.first;


}

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

       int n=difficulty.size();
       int m=worker.size();

       vector<pair<int,int>>vec(n);

       for(int i=0;i<n;i++)
       {

          vec[i]={difficulty[i],profit[i]};

       }

       sort(vec.begin(),vec.end(),cmp);
       sort(worker.begin(),worker.end());

       int ttl_profit=0;

       int mxwrkr_prft=0;
       int i=0;
       for(auto w:worker)
       {
          while(i<n && vec[i].first<=w)
          {
            mxwrkr_prft=max(mxwrkr_prft,vec[i].second);
            i+=1;
          }
          ttl_profit+=mxwrkr_prft;
       }


       return ttl_profit;

    }
};