#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main(){

    int r, g, b;
    cin >> r >> g >> b;
    string c;
    cin >> c;
    if(c=="Red")
        cout << min(g, b)<<endl;
    else if(c=="Green")
        cout << min(r, b) << endl;
    else if(c=="Blue")
        cout << min(r, g)<<endl;

    return 0;
}