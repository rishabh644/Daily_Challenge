#include<iostream>
#include<bits/stdc++.h>
#include<numeric>

using namespace std;

#define int long long

bool check(int x,int y,string& s,string t)
{

  while(x>=0 && y>=0)
  {
     if(s[x]==t[y])
     {
       x--;
       y--;
     }
     else if(s[x]=='?')
     {
       s[x] = t[y];
       x--;
       y--;
     }
     else
     {
       x--;
     }

  }
  // if all characters of t are matched
  if(y<0)
  {
      while(x>=0)
      {
        if(s[x]=='?')
        {
          s[x] = 'a';
        }
        x--;
      }
      return true;
  }

  return false;
}

int32_t main(){

  int t;
  cin>>t;
  while(t--)
  {
      string s,t;

      cin >> s;
      cin >> t;

      int n = s.size();
      int m = t.size();

      int i = n - 1;
      int j = m - 1;

      if(check(i, j, s, t))
      {
        cout<<"YES"<<endl;
        cout<<s<<endl;
      }
      else
      {
        cout<<"NO"<<endl;
      }

  }
   return 0;
}