#include<bits/stdc++.h>
#define ll long long
#define PLL pair<ll,ll>
#define fi first
#define se second
#define int long long
using namespace std;
void solve()
{
    int n,f,k;
    cin>>n>>f>>k;
    vector<int>a(n+1);
    int tem=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==f)tem=a[i];
    }
    sort(a.begin()+1,a.end(),[&](int x,int y)
    {
        return x>y;
    });
    int mn=1e13,mx=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==tem)
        {
            mn=min(mn,i);
            mx=max(mx,i);
        }
    }
    if(mx<=k)
        cout<<"YES\n";
    else if(mn>k)
        cout<<"NO\n";
    else
        cout<<"MAYBE\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
        solve();
    return 0;
}