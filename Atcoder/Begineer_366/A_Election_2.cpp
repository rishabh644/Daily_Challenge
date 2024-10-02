#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main(){

    int N, T, A;

    cin >> N >> T >> A;

    int left_vt = N - (T + A);

    if((T-A)>left_vt || (A-T)>left_vt)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}