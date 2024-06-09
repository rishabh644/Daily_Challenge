#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, f, k,vl;
        cin >> n >> f >> k;
        int arr[n];
        for (auto i = 0; i < n;i++)
            {
              cin >> arr[i];
              if(i==f-1)
                  vl = arr[i];
            }
        sort(arr, arr + n, greater<int>());

        int i = 0;
        int l=-1, h=-1;
        while(i<n)
        {
            if (arr[i] == vl)
            {
                if (l == -1)
                    l = i;

                h = i;
          }
          i++;
        }
        if((h+1)<=k)
            cout << "YES"<<endl;
        else if((l+1)>k)
            cout << "NO"<<endl;
        else
            cout << "MAYBE"<<endl;
    }
    return 0;
}