#include<iostream>
#include<bits/stdc++.h>
#include<numeric>

using namespace std;

#define lli long long

#define vi vector<long long>

#define e endl

#define co cout

#define ci cin
int convert_to_int(string s)
{
    int i = 0;
    int n = 0;

    while(i<s.size())
    {
        int vl = s[i] - '0';
        n = n * 10 + vl;
        i += 1;
    }

    return n;
}
int32_t main(){

  int t;
  cin>>t;
  while(t--)
  {
      int n;
      cin >> n;
      string s = to_string(n);

      if(s.size()>=3 && s[0]=='1' && s[1]=='0' && s[2]!='0')
      {
          string temp = s.substr(2);
          int t = convert_to_int(temp);
         // cout << "power " << t << endl;
          if(t>=2)
              cout << "YES" << endl;
          else
              cout << "NO" << endl;
      }
      else
      {
          cout << "NO" << endl;
      }

  }
   return 0;
}