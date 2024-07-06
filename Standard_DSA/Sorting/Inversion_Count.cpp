#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int merge(long long arr[],int m,int n,int p,int q)
    {
        long long temp[q-m+1];

        int t=0;

        long long int count=0;

        int s = m;

        while(m<=n && p<=q)
        {
            if(arr[m]<=arr[p])
            {
                temp[t]=arr[m];
                m+=1;
            }
            else
            {
                temp[t]=arr[p];
                count+=(n-m+1);
                p+=1;

            }

            t+=1;
        }

        while(m<=n)
        {
                temp[t]=arr[m];
                m+=1;
                t+=1;
        }



        while(p<=q)
        {
             temp[t]=arr[p];
             p+=1;
             t+=1;
        }

        t=s;

        while(t<=q)
        {
            arr[t]=temp[t-s];

            cout << "t " << t << " arr[t] " << arr[t] << endl;

            t+=1;
        }

        cout<<" count "<<count<<endl;
        return count;
    }

    void merge_sort(long long arr[],int i,int j,long long int& ans)
    {
        if(i<j)
        {
            int mid=(i+j)/2;

            merge_sort(arr,i,mid,ans);
            merge_sort(arr,mid+1,j,ans);

            ans+=merge(arr,i,mid,mid+1,j);
        }


    }
    long long int inversionCount(long long arr[], int n) {
        // Your Code Here


        int i=0;
        int j=n-1;

        long long int ans=0;

        merge_sort(arr,i,j,ans);

        return ans;
    }


int main()
{
    int n = 5;
    long long arr[n] = {2, 4, 1, 3, 5};

    cout<<inversionCount(arr, n)<<endl;

}