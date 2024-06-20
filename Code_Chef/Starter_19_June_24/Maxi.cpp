#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

	int t;

	cin>>t;

	while(t--)
	{
	    int n;
        int cnt;
        cin>>n;

	    if(n%2==0)
	    {
	        cnt=1;

	       while(cnt<=n)
	       {
	           cout<<cnt<<" ";
	           cnt=cnt+1;
	       }
	       cout<<endl;
	       cnt=n;

	       while(cnt>=1)
	       {
	           cout<<cnt<<" ";
	           cnt=cnt-1;
	       }
	       cout<<endl;

	    }
	    else
	    {
	        cnt=1;

	       while(cnt<=n)
	       {
	           cout<<cnt<<" ";
	           cnt+=1;
	       }
	       cout<<endl;
	       cnt=n;

	       int mid=(n+1)/2;

	       while(cnt>mid)
	       {
	           cout<<cnt<<" ";
	           cnt-=1;
	       }

	       cnt=1;

	       while(cnt<=mid)
	       {
	           cout<<cnt<<" ";
	           cnt+=1;
	       }
	       cout<<endl;

	    }


	}


	return 0;

}
