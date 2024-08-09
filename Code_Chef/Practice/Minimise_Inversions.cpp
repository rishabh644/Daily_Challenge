#include<iostream>
#include<bits/stdc++.h>
#include<numeric>

using namespace std;

#define int long long

#define e endl

#define co cout

#define ci cin

int invs(int x,int y,string s)
{
    int n = s.size();
    for (int i = 0; i < n;i++)
    {
       if(s[i]=='1' && x>0)
       {
           s[i] = '0';
           x--;
       }
    }
    for (int i = n - 1; i >= 0;i--)
    {
        if(s[i]=='0' && y>0)
        {
            s[i] = '1';
            y--;
        }

    }

    int os = 0, cnt = 0;

    for (int i = 0; i < n;i++)
    {
         if(s[i]=='1')
            os++;
         else
             cnt += os;
    }

    return cnt;
}


int32_t main(){

  int t;
  cin>>t;
  while(t--)
  {
      int n, k;
      cin >> n >> k;
      string s;
      cin >> s;

      int ans = invs(0, 0, s);

      for (int i = 0; i <= k;i++)
      {
          ans = min(ans, invs(i, k - i, s));
      }
      cout << ans << '\n';
  }
   return 0;
}