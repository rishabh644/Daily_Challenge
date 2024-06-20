#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define int long long

void solve(int n){

  if(n==3)
  {
      cout <<"3"<<" "<<"2"<<" "<<"1"<< endl;
      return;
}

  cout << n - 1 << " ";
  cout << n - 2 << " ";

  int i = 1;
  while(i<=(n-3))
  {
      cout << i << " ";
      i += 1;
  }
  cout << n << endl;
}

int32_t main(){

  int t;
  cin>>t;
  while(t--)
  {  int n;
      cin >> n;
      solve(n);
  }
   return 0;
}