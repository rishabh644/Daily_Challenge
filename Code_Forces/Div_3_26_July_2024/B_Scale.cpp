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
      int n, k;

      cin >> n >> k;

      vector<string> a(n);

      for(auto &s:a)
          cin >> s;
      for (int i = 0; i < n;i+=k)
      {
          for (int j = 0; j < n;j+=k)
          {
              cout << a[i][j];
          }
          cout << endl;
      }
  }
   return 0;
}