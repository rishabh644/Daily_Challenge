class Solution {

private:
vector<vector<int>>memo;
int m,n;

vector<vector<int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};

int dfs(vector<vector<int>>&matrix,int i,int j)
{
    if(memo[i][j]!=0)
    return memo[i][j];

    int ans=1;
    // Every cell itself is a path of length 1

    for(const auto& d:dirs)
    {
        int x=i+d[0];
        int y=j+d[1];

        if(x>=0 && x<m && y>=0 && y<n && matrix[x][y]>matrix[i][j])
        {
            ans=max(ans,1+dfs(matrix,x,y));
        }

    }

    memo[i][j]=ans;

    return ans;


}

public:
int longestIncreasingPath(vector<vector<int>>&matrix)
{
      if(matrix.empty())
      return 0;
      m=matrix.size();
      n=matrix[0].size();

      memo=vector<vector<int>>(m,vector<int>(n,0));
      int ans=0;

      for(int i=0;i<m;++i)
      {

        for(int j=0;j<n;++j)
        {
            ans=max(ans,dfs(matrix,i,j));
        }

      }

      return ans;
}


};