#include<iostream>
#include<bits/stdc++.h>
#include<numeric>

using namespace std;

#define int long long

int32_t main(){

    char c = 'b';

    c^=256;

    if(c!='b')
        cout << "Not equal because ninth bit toggled" << endl;

    else
        cout << "equal" << endl;
    return 0;
}