#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define int long long


void solve(int n)
{

    vector<int> arrival(n);
    vector<int> departure(n);

    for (int i = 0; i < n;i++)
    {
        cin >> arrival[i];
    }
    for (int i = 0; i < n;i++)
    {
        cin >> departure[i];
    }

    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int i = 0;
    int j = 0;

    int cnt = 0;

    int ans = 0;

    while(i<n)
    {
          if(arrival[i]<departure[j])
          {
              cnt += 1;
              i++;
          }
          else
          {
              cnt -= 1;
              j++;
          }

          ans = max(cnt, ans);
    }

    cout << ans << endl;
}


int32_t main(){

  int t;
  cin>>t;
  while(t--)
  {
      int n;
      cin >> n;
      solve(n);
  }
   return 0;
}