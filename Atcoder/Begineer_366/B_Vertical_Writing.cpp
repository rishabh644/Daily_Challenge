#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{
    multiset<int> mymultiset;
    int q;
    cin >> q;
    int qi, x;
    while(q--)
    {
        cin >> qi >> x;
        if(qi==1)
        {
            mymultiset.insert(x);
        }
        else if(qi==2)
        {
            mymultiset.erase(x);
        }
        else
        {
            unoordered_set<int> ust(mymultiset.begin(), mymultiset.end());
            cout << ust.size() << endl;
        }
    }





}