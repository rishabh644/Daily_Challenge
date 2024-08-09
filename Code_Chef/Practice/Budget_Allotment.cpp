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
      int n, x;

      cin >> n >> x;

      vector<int> a(n, 0);
      int ex = 0;
      int i = 0;
      while(i<n)
      {

          cin >> a[i];
          if(a[i]>x)
          {
              ex += (a[i] - x);
          }
          i += 1;
      }

      i = 0;
      int ans = 0;
      while(i<n)
      {
          if( a[i]>=x)
              ++ans;
          else if(ex>=(x-a[i]))
          {
              ex -= (x - a[i]);
              ++ans;
          }

          i += 1;
      }

      cout << ans << endl;
  }
   return 0;
}