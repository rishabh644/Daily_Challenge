#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{

    int pr[] = {5, 2};

    int pr1[] = {9, 5};

    int  pr2[2]={pr1[0] - pr[0], pr1[1] - pr[1]};

    cout << pr[0] << " " << pr[1] << endl;
    cout << pr2[0] << " " << pr2[1] << endl;
    return 0;

}