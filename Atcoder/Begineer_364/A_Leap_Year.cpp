#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{

    int y;

    cin >> y;

    if( (y%4!=0) || (y%100==0 && y%400!=0) )
    {    cout << 365 << endl;
    }
    else
    {
    cout << 366 << endl;
    }

    return 0;
}