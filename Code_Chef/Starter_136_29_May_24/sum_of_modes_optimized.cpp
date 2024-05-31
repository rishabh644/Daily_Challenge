#include <bits/stdc++.h>

using namespace std;

#define int long long

void number_of_modes(string s,int n)
{

map<int, int> mp;
    int sum = 0;
    int cnt = 0;
    mp[0] = 1;
    for(int i=0;i<n;i++){
        sum += (s[i]=='0') ? 1 : -1;
        if(mp.find(sum) != mp.end()){
            cnt += mp[sum];
        }
        mp[sum]++;
    }
    int ans = n*(n+1)/2;
    cout<<ans+cnt<<"\n";
}

int32_t main()
{
    int t;
	int n;
	string s;
	cin>>t;

	while(t--)
	{
	    cin>>n;
	    cin>>s;

	  number_of_modes(s,n);


	}

	return 0;
}