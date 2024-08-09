#include<iostream>
#include<bits/stdc++.h>
#include<numeric>

using namespace std;

#define lli long long

#define e endl

#define co cout

#define ci cin

#define vi vector<long long>
lli score(int a,int b)
{
   if(a>b)
       return 1;
   else if(a<b)
       return -1;
   else
       return 0;
}

int main(){

  lli t;
  cin>>t;
  while(t--)
  {
      vi a(2), b(2);
      cin >> a[0] >> a[1];
      cin >> b[0] >> b[1];
      lli ans = 0;
      if((score(a[0],b[0])+score(a[1],b[1]))>0)
          ans += 2;
      if((score(a[0],b[1])+score(a[1],b[0]))>0)
          ans += 2;
      cout << ans << endl;
  }
   return 0;
}