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
      vector<int> vec(n);
      vector<int> ps(n, 0);
      vector<int> ss(n, 0);
      for(auto& x:vec)
      {
          cin >> x;
      }
      string s;
      cin >> s;
      for (int i = 1; i < n;i++)
      {
          ps[i] = ps[i - 1] + vec[i - 1];
      }
      for (int j = n - 2; j >= 0;j--)
      {
          ss[j] = ss[j + 1] + vec[j + 1];
      }

      int ts = ps[n - 1] + vec[n - 1];


      int i = 0, j = n - 1;
      int ans = 0;
      while(i<j)
      {
        if(s[i]=='L' && s[j]=='R')
        {
            ans = ans + ts - (ps[i] + ss[j]);
            i++;
            j--;
        }
        else{
        if(s[j]=='L')
            j -= 1;
        if(s[i]=='R')
            i += 1;}
      }
      cout << ans << endl;
  }
   return 0;
}