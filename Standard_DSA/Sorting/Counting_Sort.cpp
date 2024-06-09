#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void counting_sort(vector<int>&A,vector<int>&B)
{
    vector<int> C(10, 0);

    int i = 0;
    int n = A.size();

    while(i<n)
    {
        C[A[i]]++;
        i++;
    }
    for (i = 1; i <= 9;i++)
    {
        C[i] = C[i] + C[i - 1];
    }

    for (i = n - 1; i >= 0;i--)
    {
        B[C[A[i]]] = A[i];
        C[A[i]] -= 1;
    }
}

int main()
{
    // vector<int> A;
    int n;

    cout << "Enter size of array" << endl;
    cin >> n;

    vector<int> A(n, 0);
    vector<int> B(n+1, 0);

    cout << "Enter " << n << " no of elements." << endl;

    for (int i = 0; i < n;i++)
    {
        cin >> A[i];
    }

    cout << "See after sorting " << n << " no of elements. " << endl;

    counting_sort(A, B);

    for (int i = 1; i <= n;i++)
    {
        cout << B[i] << " ";
    }

    cout << endl;

    return 0;
}