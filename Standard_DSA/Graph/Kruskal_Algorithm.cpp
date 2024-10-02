#include<iostream>
#include<bits/stdc++.h>

using namespace std;


bool my_cmp(vector<int>&a,vector<int>&b)
{
    return a[2]<b[2];
}

class Disjointset{
  int* arr;
  int* size;

  public:
   Disjointset(int n)
   {
       arr=new int[n+1];
       size=new int[n+1];

       for(int i=1;i<=n;i++)
       {
           arr[i]=i;
           size[i]=1;
       }
   }
   int find(int x)
   {
       if(x==arr[x])
       return x;

       return arr[x]=find(x);

   }

   void unionsets(int x,int y)
   {
       int upx=find(x);
       int upy=find(y);
       if(size[upx]<size[upy])
       {
           arr[upx]=upy;
           size[upy]+=size[upx];
       }
       else
       {
           arr[upy]=upx;
           size[upx]+=size[upy];
       }

   }



};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adjlist[])
    {
        // code here

        vector<vector<int>>edgelist;

        for(int i=0;i<V;i++)
        {
            for(auto e:adjlist[i])
            {
                edgelist.push_back({i,e[0],e[1]});
            }
        }


        Disjointset obj(V);



        sort(edgelist.begin(),edgelist.end(),my_cmp);

        int cost=0;

        for(auto e:edgelist)
        {
            int x=e[0];
            int y=e[1];
            int c=e[2];

            if(obj.find(x)!=obj.find(y))
            {
                obj.unionsets(x,y);
                cost+=c;
            }

        }

        return cost;
    }
};

int main()
{



}