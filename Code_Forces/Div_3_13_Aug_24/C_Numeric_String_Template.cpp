#include<iostream>
#include<bits/stdc++.h>
#include<numeric>

using namespace std;

#define lli long long

#define vi vector<long long>

#define e endl

#define co cout

#define ci cin

bool match(vi& vec,string& s)
{

    if(vec.size()!=s.size())
        return false;
    unordered_map<int, char> ump;
    unordered_map<char, int> umpr;
    int i = 0;
    int n = vec.size();

    while(i<n)
    {
        if(ump.find(vec[i])!=ump.end())
        {
          if(ump[vec[i]]!=s[i])
          {
              return false;
          }
        }
        if(umpr.find(s[i])!=umpr.end())
        {
         if(umpr[s[i]]!=vec[i])
          {
              return false;
          }

        }
        ump[vec[i]] = s[i];
        umpr[s[i]] = vec[i];

        i++;
    }

    return true;
}

int32_t main()
{

  int t;
  cin>>t;
  while(t--)
  {

      int n;
      cin >> n;
      vi vec(n);
      for(auto& x:vec)
      {
          cin >> x;
      }
      int m;
      cin >> m;
      vector<string> st(m);
      for(auto& s:st)
      {
          cin >> s;

          if(match(vec,s))
          {
              cout << "YES" << endl;
          }
          else
          {
              cout << "NO" << endl;
          }
      }



  }
   return 0;
}