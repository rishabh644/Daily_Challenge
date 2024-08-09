#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{

    int n,i,fm,sm;
    cin >> n;

    vector<int> vec(n, 0);

    for (i = 0; i < n;i++)
    {
        cin >> vec[i];
    }

    fm = 0;
    sm = -1;
    for (i = 1; i < n;i++)
    {
        if(vec[i]>vec[fm])
        {
            sm = fm;
            fm = i;
        }
        else if(sm==-1 ||vec[i]>vec[sm])
            sm = i;
    }

    cout << sm+1 << endl;
}