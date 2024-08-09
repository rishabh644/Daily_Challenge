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
     ci>> n;
     co << n / 10 + n % 10 << e;
  }
   return 0;
}