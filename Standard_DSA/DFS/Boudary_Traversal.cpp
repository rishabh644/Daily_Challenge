vector<pair<int,int>>mov={{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<char>>&board,vector<vector<int>>&visited,int i,int j)
    {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='X' || visited[i][j]==1)
        return;

        visited[i][j]=1;

        for(auto mv:mov)
        {
            dfs(board,visited,i+mv.first,j+mv.second);
        }



    }
    void solve(vector<vector<char>>& board) {

         int m=board.size();
         int n=board[0].size();

         int i,j;

         vector<vector<int>>visited(m,vector<int>(n,0));

         for(j=0;j<n;j++)
         {
            if(board[0][j]=='O' && !visited[0][j])
            dfs(board,visited,0,j);
         }

         for(i=0;i<m;i++)
         {
            if(board[i][0]=='O' && !visited[i][0])
            dfs(board,visited,i,0);
         }

         if(m>1)
         {
            for(j=0;j<n;j++)
            {
            if(board[m-1][j]=='O' && !visited[m-1][j])
            dfs(board,visited,m-1,j);
            }

         }

         if(n>1)
         {

           for(i=0;i<m;i++)
           {
            if(board[i][n-1]=='O' && !visited[i][n-1])
            dfs(board,visited,i,n-1);
           }

         }

         for(i=0;i<m;i++)
         {
            for(j=0;j<n;j++)
            {
                if(board[i][j]=='O' && !visited[i][j])
                board[i][j]='X';
            }
         }

    }