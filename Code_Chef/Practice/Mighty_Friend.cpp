#include<iostream>
#include<bits/stdc++.h>
#include<numeric>

using namespace std;

#define int long long

void swap(int &a,int &b)
{
   int t=a;
   a=b;
   b=t;

}

void solve()
{
    int n, k;

    cin >> n >> k;

    vector<int> vec(n);

    vector<int> motu;
    vector<int> tomu;

    for (int i = 0; i < n;i++)
    {
        cin >> vec[i];

        if(i%2==0)
        {
            motu.push_back(vec[i]);
        }
        else
        {
            tomu.push_back(vec[i]);
        }

    }

    sort(motu.begin(), motu.end());
    sort(tomu.begin(), tomu.end());

    int i = motu.size() - 1;
    int j = 0;

    int count = 0;

    while(i>=0 && j<tomu.size() && count<k)
    {
        if(motu[i]>tomu[j])
        {
            swap(motu[i], tomu[j]);
            i--;
            j++;
            count++;
        }
        else if(motu[i]==tomu[j])
       {
           i--;
           j++;
       }
       else
       {
           break;
       }
    }

    if(accumulate(tomu.begin(), tomu.end(), 0) > accumulate(motu.begin(), motu.end(), 0))
    {
        cout << "YES"<<endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}


int32_t main(){

  int t;
  cin>>t;
  while(t--)
  {
      solve();
  }
   return 0;
}