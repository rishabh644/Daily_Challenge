    void dfs(int x,int y,vector<vector<int>>& heights,vector<vector<bool>>&vis,int prev,int curr,int& cost)
    {

       if(x<0 || y<0 || x>=heights.size() || y>=heights[0].size() || vis[x][y]==true)
       return;

       vis[x][y]=true;

       int ch=heights[x][y];

       curr=max(curr,ch-prev);

       if(x==heights.size()-1 && y==heights[0].size()-1)
       {
        cost=min(cost,curr);
        vis[x][y]=false;
        return;
       }

       dfs(x-1,y,heights,vis,ch,curr,cost);
       dfs(x+1,y,heights,vis,ch,curr,cost);
       dfs(x,y-1,heights,vis,ch,curr,cost);
       dfs(x,y+1,heights,vis,ch,curr,cost);

       vis[x][y]=false;

       return;



    }
    int minimumEffortPath(vector<vector<int>>& heights) {

    int m=heights.size();
    int n=heights[0].size();

    int cost=INT_MAX;

    vector<vector<bool>>vis(m,vector<bool>(n,false));

    dfs(0,0,heights,vis,heights[0][0],INT_MIN,cost);

    return cost;

    }

// Time Complexity is O(V+E)
// V=M*N
// E=M*(N-1)+N*(M-1)
// TC is O(V+E)

// O(V+E) seems smaller, DFS’s exploration can grow exponentially in practice because it may revisit nodes and explore many non-optimal paths.
// Dijkstra’s algorithm, despite the higher theoretical time complexity, provides a more practical and efficient solution due to its
// focused exploration and use of a priority queue. This makes it better suited for problems involving finding the minimum
// cost or effort path, as it avoids unnecessary computations and directly targets the optimal solution.
// In summary, while O(V+E) is asymptotically smaller, the practical performance of DFS can be poor for pathfinding problems.
// Dijkstra’s algorithm, though it has a higher theoretical complexity, is often more efficient in practice
//  for finding optimal paths due to its targeted and efficient exploration strategy.
class CMP{
public:
bool operator()(vector<int>&a,vector<int>&b)
{
    return b[2]<a[2];
}


};

class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {

    int m=heights.size();
    int n=heights[0].size();

    if(m==1 && n==1)
    return 0;

    vector<vector<int>>distance(m,vector<int>(n,INT_MAX));

    vector<vector<int>>movement={{-1,0},{0,1},{1,0},{0,-1}};


    distance[0][0]=0;

    priority_queue<vector<int>,vector<vector<int>>,CMP>pq;

    pq.push({0,0,0});

    while(!pq.empty())
    {
        vector<int>temp=pq.top();
        pq.pop();
        int x=temp[0];
        int y=temp[1];
        int c=temp[2];

        if(x==m-1 && y==n-1)
        return c;

        if(distance[x][y]<c)
        continue;

        for(auto mv:movement)
        {
            int xx=x+mv[0];
            int yy=y+mv[1];
           if(xx>=0 && xx<m && yy>=0 && yy<n)
           {

           if(distance[xx][yy]>max(c,abs(heights[xx][yy]-heights[x][y])) )
           {
            distance[xx][yy]=max(c,abs(heights[xx][yy]-heights[x][y]));
            pq.push({xx,yy,distance[xx][yy]});
           }

           }

        }


    }

    return -1;

    }
};
/////////////////////////////////////////-------------------------///////////////////////////
bool canReachWithEffort(vector<vector<int>>&heights,int maxEffort)
    {
        int m=heights.size();
        int n=heights[0].size();

        vector<vector<bool>>visited(m,vector<bool>(n,false));

        queue<pair<int,int>>q;

        q.push({0,0});

        visited[0][0]=true;

        vector<int>directions={-1,0,1,0,-1};

        while(!q.empty())
        {

            auto [x,y]=q.front();
            q.pop();

            if(x==m-1 && y==n-1)
            {
                return true;
            }

            for(int i=0;i<4;++i)
            {
                  int newX=x+directions[i];
                  int newY=y+directions[i+1];


            if(newX>=0 && newX<m && newY>=0 && newY<n && !visited[newX][newY])
            {

               int currentEffort=abs(heights[newX][newY]-heights[x][y]);
               if(currentEffort<=maxEffort)
               {
                q.push({newX,newY});
                visited[newX][newY]=true;
               }

            }

            }




        }


        return false;


    }


    int minimumEffortPath(vector<vector<int>>& heights) {

    int m=heights.size();
    int n=heights[0].size();

    int left=0;
    int right=0;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
           for(int k=0;k<4;k++)
           {

             int newX=i+(k==0?-1:(k==2?1:0));
             int newY=j+(k==1?1:(k==3?-1:0));

             if(newX>=0 && newX<m && newY>=0 && newY<n)
             {
                right=max(right,abs(heights[i][j]-heights[newX][newY]));
             }

           }
        }
    }

    int ans;
    while(left<=right)
    {
       int mid=(left+right)/2;

       if(canReachWithEffort(heights,mid))
       {
        ans=mid;
        right=mid-1;
       }
       else
       {
        left=mid+1;
       }

    }

    return ans;

    }
/////////////////////////////////////////////////---------------------------------------///////////////////////////////
