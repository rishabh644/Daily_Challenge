#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int minIteration(int N, int M, int x, int y){
        // code here


        vector<vector<int>>visited(N,vector<int>(M,0));

        queue<pair<int,int>>qu;

        qu.push({x,y});

        vector<pair<int,int>>mov={{-1,0},{1,0},{0,1},{0,-1}};
        pair<int,int>p;

        int it=0;
        visited[x][y]=1;

        while(!qu.empty())
        {

            int sz=qu.size();

            for(int i=0;i<sz;i++)
            {
                pair<int,int>p=qu.front();
                qu.pop();
                for(auto mv:mov)
                {
                    int xx=mv.first+p.first;
                    int yy=mv.second+p.second;

                    if(xx>=0 && xx<N && yy>=0 && yy<M && visited[xx][yy]==0)
                    {
                        qu.push({xx,yy});
                        visited[xx][yy]=1;
                    }


                }
            }

        if(!qu.empty())
        {
            ++it;
        }

        }

        return it;
    }

int main()
{

   cout<<minIteration(2,3,)

}