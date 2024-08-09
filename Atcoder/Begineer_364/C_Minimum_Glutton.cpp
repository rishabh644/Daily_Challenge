#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define int long long



int32_t main()
{

    int n, x, y;

    cin >> n >> x >> y;

    vector<int> disha(n, 0);
    vector<int> dishb(n, 0);

    int ans;

    for(auto& x:disha)
    {
        cin >> x;
    }

    for(auto& y:dishb)
    {
        cin >> y;
    }

    sort(disha.begin(), disha.end(), greater<int>());
    sort(dishb.begin(), dishb.end(), greater<int>());

    int sx = 0,ax=disha.size(),sy=0,ay=dishb.size();

    for (int i = 1; i <= disha.size();i++)
    {
        sx += disha[i - 1];

        if(sx>x)
        {
            ax = i;
            break;
        }

    }

    for (int i = 1; i <= dishb.size();i++)
    {
        sy += dishb[i - 1];

        if(sy>y)
        {
            ay = i;
            break;
        }
    }

        cout << min(ax,ay) << endl;

    return 0;
}