#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{
    unordered_map<int,int> ump;
    int count = 0;
    int q;
    cin >> q;
    int qi, x;
    while(q--)
    {
        cin >> qi;
        if(qi==1)
        {
            cin >> x;
            ump[x] += 1;
            if(ump[x]==1)
                count += 1;
        }
        else if(qi==2)
        {
            cin >> x;
            ump[x] -= 1;
            if(ump[x]==0)
                count -= 1;
        }
        else
        {
            cout << count << endl;
        }
    }

    return 0;
}