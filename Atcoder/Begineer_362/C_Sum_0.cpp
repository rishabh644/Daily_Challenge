#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main(){

    int n;
    cin >> n;

    int x, y;

    vector<vector<int>> vec;

    int i = 0;

    ll sx = 0;
    ll sy = 0;

    while(i<n)
    {

        cin >> x >> y;

        vec.pb({x, y});
        sx += x;
        sy += y;
        i += 1;
    }
    i = 0;
    if(sx<=0 && sy>=0)
    {
        cout << "Yes" << endl;
        for (i = 0; i < n;i++)
        {
            if(sx>=0)
            {
                 break;
            }
            else
            {
                sx += (vec[i][1] - vec[i][0]);
            }
        }

        if(sx==0)
        {
            int k;
            for (k = 0; k < i;k++)
            {
                cout << vec[k][1] << " ";
            }
            for (k = i; k < n;k++)
            {
                cout << vec[k][0] << " ";
            }
            cout << endl;
        }
        else
        {
            int k;
            for ( k = 0; k < (i - 1);k++)
            {
                 cout << vec[k][1] << " ";
            }

            cout << vec[k][1] - sx<<" ";
            for ( k = i; k < n;k++)
            {
                cout << vec[k][0] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}