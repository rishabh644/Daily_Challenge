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
      int n;
      cin >> n;
      vi vec(n);
      for(auto &x:vec)
      {
          cin >> x;
      }
      vector<bool>vis(n + 1, false);
      bool flag = true;
      for(int i = 0; i < n;i++)
      {

        if(i!=0 && !vis[vec[i]-1] && !vis[vec[i]+1])
        {
            flag = false;
            break;
        }
        vis[vec[i]] = true;
      }
     if(flag)
         cout << "YES" << endl;
     else
         cout << "NO" << endl;
  }
   return 0;
}