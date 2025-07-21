class Solution {
private:
    vector<int>mov={-1,0,1,0,-1};
public:
    void dfs(vector<vector<int>>& heights,vector<vector<int>>& ocn,int x,int y)
    {


      ocn[x][y]=1;

      int m=heights.size();
      int n=heights[0].size();

      for(int k=0;k<4;k++)
      {

        int xx=x+mov[k];
        int yy=y+mov[k+1];
        if(xx>=0 && xx<m && yy>=0 && yy<n && heights[xx][yy]>=heights[x][y] && ocn[xx][yy]==0){
            dfs(heights,ocn,xx,yy);
     }

     }


    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {

       int m=heights.size();
       int n=heights[0].size();

       vector<vector<int>>pacf(m,vector<int>(n,0));
       vector<vector<int>>atln(m,vector<int>(n,0));


       // top row

       for(int j=0;j<n;j++)
       {
       dfs(heights,pacf,0,j);
       }
       // left col

       for(int i=0;i<m;i++)
       {
        dfs(heights,pacf,i,0);
       }



       for(int j=0;j<n;j++)
       {
       dfs(heights,atln,m-1,j);
       }

       for(int i=0;i<m;i++)
       {
        dfs(heights,atln,i,n-1);
       }

       vector<vector<int>>ans;

       for(int i=0;i<m;i++)
       {
          for(int j=0;j<n;j++)
          {
             if(pacf[i][j]==1 && atln[i][j]==1)
             ans.push_back({i,j});
          }

       }

       return ans;

    }
};