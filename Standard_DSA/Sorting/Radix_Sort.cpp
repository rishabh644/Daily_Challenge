#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void Radix_Sort(vector<int>&A,int d)
{
    for (int i = 1; i <= d;i++)
    {
        counting_sort(A,i);
    }

}


int main()
{

    vector<int> A = {329, 457, 657, 839, 436, 720, 355};

    int i;
    int n = A.size();

    for (i = 0; i < n;i++)
    {
        cout << A[i] << " ";
    }

    cout << endl;

    return 0;
}