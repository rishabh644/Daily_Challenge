#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{

  int n;
  cin >> n;
  int i = 0;
  string s;
  bool l = false;
  string ans="Yes";
  while(i<n)
  {
      cin >> s;
      if(s[0]=='s' && s[1]=='w')
      {
          if(i!=n-1 && l==true)
          {
              ans = "No";
          }
          l = true;
      }
      else
      {
          l = false;
      }

      i += 1;
  }

  cout << ans << endl;

  return 0;
}