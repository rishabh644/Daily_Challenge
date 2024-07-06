
bool my_cmp(long long &a,long long &b)
{
    return a>b;
}

class Solution {
public:


    long long maximumImportance(int n, vector<vector<int>>& roads)
    {
         vector<long long>in_deg(n,0);

         for(int i=0;i<roads.size();i++)
         {
            in_deg[roads[i][0]]++;
            in_deg[roads[i][1]]++;
         }

         sort(in_deg.begin(),in_deg.end(),my_cmp);

         long long ans=0;

         long long mul=n;

         for(int i=0;i<n;i++)
         {
            ans=ans+in_deg[i]*mul;

            mul-=1;
         }

         return ans;

    }
};