#include<iostream>
#include<bits/stdc++.h>
#include<numeric>

using namespace std;

#define int long long

#define e endl

#define co cout

#define ci cin

int32_t main(){

  int t;
  cin>>t;
  while(t--)
  {
      int n, s, m;
      cin >> n >> s >> m;
      int x, y;
      int lst = 0;
      bool cr = false;
      for (int i = 0; i < n;i++)
      {

          cin >> x >> y;
          if(!cr)
          {
             if( (x-lst)>=s )
                 cr = true;
          }
          lst = y;
      }
      if(!cr && (m-lst)>=s)
          cr = true;

      if(cr)
          cout << "YES" << endl;
      else
          cout << "NO" << endl;
  }
   return 0;
}