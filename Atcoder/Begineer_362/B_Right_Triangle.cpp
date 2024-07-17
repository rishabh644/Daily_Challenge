#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long distance(long long xa,long long ya,long long xb,long long yb)
{
    return (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
}

int main(){

    int xa, ya;
    int xb, yb;
    int xc, yc;

    cin >> xa >> ya;
    cin >> xb >> yb;
    cin >> xc >> yc;

    long long ab = distance(xa, ya, xb, yb);
    long long bc = distance(xb, yb, xc, yc);
    long long ac = distance(xa, ya, xc, yc);

    if(ab==bc+ac)
        cout << "Yes" << endl;
    else if(bc==ab+ac)
        cout << "Yes" << endl;
    else if(ac==ab+bc)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}