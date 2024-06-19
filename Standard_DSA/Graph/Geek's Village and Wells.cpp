Geek's village is represented by a 2-D matrix of characters of size n*m, where

H - Represents a house
W - Represents a well
. - Represents an open ground
N - Prohibited area(Not allowed to enter this area)

Every house in the village needs to take water from a well, as the family members are
so busy with their work, so every family wants to take the water from a well in minimum time,
which is possible only if they have to cover as less distance as possible. Your task is to determine
the minimum distance that a person in the house should travel to take out the water and carry it back to the house.

A person is allowed to move only in four directions left, right, up, and down. That means if he/she is the cell (i,j),
then the possible cells he/she can reach in one move are (i,j-1),(i,j+1),(i-1,j),(i+1,j), and the person is not allowed to
move out of the grid.

Note: For all the cells containing 'N', 'W' and '.' our answer should be 0, and for all the houses where there
is no possibility of taking water our answer should be -1.


class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        // Code here

        vector<vector<int>>time_taken(n,vector<int>(m,0));

        vector<vector<int>>visited(n,vector<int>(m,0));

        vector<pair<int,int>>directions={{-1,0},{1,0},{0,1},{0,-1}};


        queue<pair<int,int>>qu;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(c[i][j]=='W')
                {
                    visited[i][j]=1;
                    qu.push({i,j});
                }
            }
        }


        while(!qu.empty())
        {
            auto p=qu.front();

            int x=p.first;
            int y=p.second;

            qu.pop();

            for(auto dr:directions)
            {
                int nx=x+dr.first;
                int ny=y+dr.second;

                if(nx>=0 && nx<n && ny>=0 && ny<m && (c[nx][ny]=='H' || c[nx][ny]=='.') && visited[nx][ny]==0)
                {
                    visited[nx][ny]=1;
                    time_taken[nx][ny]=time_taken[x][y]+1;
                    qu.push({nx,ny});
                }


            }

        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(c[i][j]=='H' && time_taken[i][j]==0)
                time_taken[i][j]=-1;
                else if(c[i][j]=='H')
                time_taken[i][j]=2*time_taken[i][j];
                else
                time_taken[i][j]=0;
            }
        }

        return time_taken;

    }
};