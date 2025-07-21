class Cmp{
public:
  bool operator()(vector<int>&a,vector<int>&b)
  {
    return b[2]<a[2];
  }
};

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest)
    {

        int m=maze.size();
        int n=maze[0].size();

        vector<vector<int>>distance(m,vector<int>(n,INT_MAX));

        distance[start[0]][start[1]]=0;

        dijkstra(maze,start,distance);

        return distance[dest[0]][dest[1]]==INT_MAX?-1:distance[dest[0]][dest[1]];

    }

    void dijkstra(vector<vector<int>>&maze,vector<int>start,vector<vector<int>>&distance)
    {

        vector<vector<int>>dirs={{0,1},{0,-1},{-1,0},{1,0}};

        priority_queue<vector<int>,vector<vector<int>>,Cmp>pq;

        pq.push({start[0],start[1],0});

        while(!pq.empty())
        {

           vector<int>s=pq.top();
           pq.pop();

           if(distance[s[0]][s[1]]<s[2])
           continue;

           for(vector<int>dir:dirs)
           {
                 int x=s[0]+dir[0];
                 int y=s[1]+dir[1];
                 int count=0;

                 while(x>=0 && y>=0 && x<maze.size() && y<maze[0].size() && maze[x][y]==0)
                 {
                      x+=dir[0];
                      y+=dir[1];
                      count++;
                 }

                 if(distance[s[0]][s[1]]+count<distance[x-dir[0]][y-dir[1]])
                 {
                    distance[x-dir[0]][y-dir[1]]=distance[s[0]][s[1]]+count;
                    pq.push({x-dir[0],y-dir[1],distance[ x-dir[0] ][ y-dir[1] ]});
                 }

           }

        }

    }
};
//////////////////////
