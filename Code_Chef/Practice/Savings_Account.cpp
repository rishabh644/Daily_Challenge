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
      int x, y, z;
      cin >> x >> y >> z;

      int q = z / y;

      if(x<=q)
          cout << 0 << endl;
      else
          cout << x - q << endl;
  }
   return 0;
}