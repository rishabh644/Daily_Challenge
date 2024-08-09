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
     int n;

     cin >> n;

     int r = n % 4;

     if(r==2)
     {
         cout<<(n / 4 + 1)<<endl;
     }
     else
     {
         cout<<(n / 4)<<endl;
     }

  }
   return 0;
}