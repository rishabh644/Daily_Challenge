#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main(){

    int n, t, p;

    cin >> n >> t >> p;

    vector<int> vec(n, 0);

    for (int i = 0; i < n;i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end(), greater<int>());

    if(vec[p-1]>=t)
        cout << 0 << endl;
    else
        cout << t - vec[p - 1] << endl;
    return 0;
}
