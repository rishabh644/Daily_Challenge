#include<iostream>
#include<bits/stdc++.h>
#include<numeric>

using namespace std;

#define lli long long

#define vi vector<long long>


int32_t main()
{
    const lli MX = 3e5;
    vi op(MX);
    for (lli j = 0; j < MX;j++)
    {
        lli cnt = 0, K = j;
        while(K>0)
        {
            K /= 3;
            cnt++;
        }

        op[j] = cnt;
    }
    vi opSum(MX);
    for (lli j = 1; j < MX;j++)
    {
        opSum[j] = opSum[j - 1] + op[j];
    }



        int t;
        cin >> t;

        while (t--)
        {
            lli l, r;
            cin >> l;
            cin >> r;
            lli ans = 0;
            ans += opSum[r] - opSum[l - 1];
            ans += op[l];
            cout << ans << endl;
        }

        return 0;

}