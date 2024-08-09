#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool isPossible(int mid,int m,vector<int>&vec)
{

    int sum=0;

    for(auto& vl:vec)
        sum += min(mid, vl);

    return sum <= m;

}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> vec(n, 0);

    int sm = 0;


    int mmax = INT_MIN;

    for(auto &v:vec)
    {
        cin >> v;
        sm += v;

        mmax = max(v, mmax);

    }
    if(sm<=m)
    {

        cout << "infinite" << endl;

    }
    else
    {
        int l = 0;
        int h = mmax;

        int mid;
        int ans=0;
        while(l<=h)
        {
            mid = (l + h) / 2;

            if(isPossible(mid,m,vec))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }

        cout<<ans<<endl;
    }




    return 0;
}