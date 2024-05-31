#include <bits/stdc++.h>
using namespace std;


int bfs(int i,int j,vector<pair<int,int>>&mov)
{


    unordered_set<string>visited;

    queue<pair<int,int>>qu;

    qu.push({0,0});

    int count=1;
    int x,y,nx,ny;
    pair<int,int>pr;

    string temp=to_string(0)+to_string(0);
    visited.insert(temp);

    while(!qu.empty())
    {
        pr=qu.front();
        x=pr.first;
        y=pr.second;
        qu.pop();

        for(auto mv:mov)
        {
            nx=x+mv.first;
            ny=y+mv.second;
            cout << nx << ","<<ny << endl;
            if(nx>=-10 && nx<=10 && ny>=-10 && ny<=10)
            {
            temp=to_string(nx)+to_string(ny);
            if(visited.find(temp)==visited.end())
            {
                count++;
                visited.insert(temp);
                qu.push({nx,ny});
            }
            }

        }

    }

    return count;

}


int main() {
	// your code goes here


	int t;

	string s;

	cin>>t;

	while(t--)
	{
	    cin>>s;
	    vector<pair<int,int>>mov;


	    if(s[0]=='1')
	    mov.push_back({0,-1});
        if (s[1] == '1')
            mov.push_back({0, 1});
	    if(s[2]=='1')
	    mov.push_back({-1,0});
	    if(s[3]=='1')
	    mov.push_back({1,0});

	    cout<<bfs(0,0,mov)<<endl;

	}

}
