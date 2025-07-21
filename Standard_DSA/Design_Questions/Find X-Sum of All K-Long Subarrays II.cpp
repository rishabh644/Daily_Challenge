class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x)
    {
        int n=nums.size();

        vector<int>ans;

        unordered_map<int,int>ump;

        int i=0,j=0;
        int sm=0;
        while(j<i+k-1)
        {
            sm+=nums[j];
            ump[nums[j]]+=1;
            j+=1;
        }

        while(j<n)
        {
            sm+=nums[j];
            ump[nums[j]]+=1;

            if(ump.size()<x)
            ans.push_back(sm);
            else
            {
                vector<pair<int,int>>vec;

                for(auto pr:ump)
                {
                    vec.push_back({pr.second,pr.first});
                }

                sort(vec.begin(),vec.end(),greater<pair<int,int>>());
                int ns=0;
                for(int k=0;k<x;k++)
                {
                    ns+=(vec[k].second*vec[k].first);
                }
                ans.push_back(ns);

            }


            sm-=nums[i];
            ump[nums[i]]-=1;

            if(ump[nums[i]]==0)
            {
                ump.erase(nums[i]);
            }

            i++;
            j++;
        }

        return ans;

    }
};

















/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<long long> findXSum(vector<int>& a, int k, int x)
    {

       int n=a.size();
       long long sum=0;
       map<int,int>mp;
       set<pair<int,int>>large,small;

       vector<long long>ans;

       for(int i=0;i<n;i++)
       {
          small.insert({mp[a[i]],a[i]});
       }

       auto update=[&](int x,int v)
       {
          if(large.count({mp[x],x}))
          {
               large.erase({mp[x],x});
               sum-=1ll*mp[x]*x;
               mp[x]+=v;
               sum+=1ll*mp[x]*x;
               large.insert({mp[x],x});
          }
          else if(small.count({mp[x],x}))
          {
              small.erase({mp[x],x});
              mp[x]+=v;
              small.insert({mp[x],x});
          }else assert(false);

       };

       auto equilbrium=[&](){

         while(large.size()<x && !small.empty())
         {
            auto second=*small.rbegin();
            large.insert(second);
            sum+=1ll*second.first*second.second;
            small.erase(second);
         }

         if(small.empty())
         return;

         while(true)
         {
            auto first=*large.begin();
            auto second=*small.rbegin();
            if(first<second)
            {
                large.erase(first);
                small.erase(second);

                large.insert(second);
                small.insert(first);

                sum-=1ll*first.first*first.second;
                sum+=1ll*second.first*second.second;

            }else break;

         }

       };

       for(int i=0;i<k;i++)
       {
         update(a[i],1);
       }

       equilbrium();
       ans.push_back(sum);

       for(int i=k;i<n;i++)
       {

           update(a[i],1);
           if(i>=k)update(a[i-k],-1);
           if(i>=k-1)
           {
             equilbrium();
             ans.push_back(sum);
           }

       }

       return ans;

    }
};