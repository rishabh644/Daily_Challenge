#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        string st;
        int arr[7]={0};
        cin >> n >> m;
        cin >> st;

        for(auto ch:st)
            arr[ch - 'A']++;
        int count = 0;
        int ans = 0;
        for(auto vl:arr)
        {
            ans += max(0, m - vl);
        }

        cout << ans << endl;
    }
    return 0;
}