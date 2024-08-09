#include<iostream>
#include<bits/stdc++.h>
#include<numeric>

using namespace std;

#define int long long

int32_t main(){

  int t;
  cin>>t;
  while(t--)
  {
      int n;
      cin >> n;
      vector<int> vec(n);
      unordered_map<int, int> ump;

      int i = 0;

      while(i<n)
      {
          cin >> vec[i];
          ump[vec[i]] += 1;
          i += 1;
      }

      vector<int> counts;

      for (auto it = ump.begin(); it != ump.end();it++)
      {
          counts.push_back(it->second);
      }
      sort(counts.begin(), counts.end(), greater<int>());

      int total = 0;
      int ans;
      int cur_tak = 0;
      for (int i = 0; i < counts.size();i++)
      {
          total+= counts[i];
          if(total%(i+1)==0)
            {
               ans = total;
            }
            else
            {
                ans = max(ans,total - total % (i+1));
            }

      }

      cout << ans << endl;
  }
   return 0;
}