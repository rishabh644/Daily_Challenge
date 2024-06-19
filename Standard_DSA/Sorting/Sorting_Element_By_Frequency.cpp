Given an array A[] of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. If frequencies of two elements are same,
then smaller number comes first.

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Cmp{
    public:
    bool operator()(pair<int,int> f,pair<int,int> s)
    {
        if(s.second==f.second)
        {
            if(f.first>s.first)
            return true;
            else
            return false;
        }
        else if(s.second>f.second)
        {
            return true;
        }
        else
        return false;

    }

};

int main()
 {
	//code
	int t;

	cin>>t;

	while(t--)
	{
	    int n,vl;
	    cin>>n;

	    unordered_map<int,int>ump;

	    while(n--)
	    {
	        cin>>vl;
	        ump[vl]+=1;
	    }

	    priority_queue<pair<int,int>,vector<pair<int,int>>,Cmp>pq;

	    for(auto it=ump.begin();it!=ump.end();it++)
	    {
	        pq.push({it->first,it->second});
	    }

	    while(!pq.empty())
	    {
	        auto pr=pq.top();

	        auto k=pr.first;
	        auto f=pr.second;

	        pq.pop();

	        while(f--)
	        {
	            cout<<k<<" ";
	        }
	    }
	    cout<<endl;


	}


	return 0;
}