#include<iostream>
#include<bits/stdc++.h>
#include<numeric>

using namespace std;

#define lli long long

#define vi vector<long long>

#define e endl

#define co cout

#define ci cin

int32_t main(){

  int t;
  cin>>t;
  while(t--)
  {
       int m;
       cin >> m;
       vector<int> ans;
       while(m--)
       {
           string s;
           cin >> s;
           int i = 0;
           while(i<4)
           {
               if(s[i]=='#')
                   ans.push_back(i + 1);
               i += 1;
           }
       }
       reverse(ans.begin(), ans.end());
       for(auto vl:ans)
           cout << vl << " ";
       cout << endl;
  }
   return 0;
}
//////////////////
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {

        deque<int>dq;
        vector<int>res;

        for(int i=0;i<k;i++)
        {
            while(!dq.empty() && nums[i]>=nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        res.push_back(nums[dq.front()]);

        for(int i=k;i<nums.size();i++)
        {
            if(dq.front()==i-k)
            {
                dq.pop_front();
            }
            while(!dq.empty() && nums[i]>=nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            res.push_back(nums[dq.front()]);

        }

         return res;

    }
};