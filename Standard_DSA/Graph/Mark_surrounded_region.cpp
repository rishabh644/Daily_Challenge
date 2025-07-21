class Solution {

    private:
    vector<int>mov={-1,0,1,0,-1};
    public:

    void dfs(vector<vector<char>>& board,vector<vector<bool>>&vis,int x,int y,bool isbound)
    {
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y]=='X' || vis[x][y])
        return;

        vis[x][y]=true;

        if(!isbound)
        board[x][y]='X';

        for(int i=0;i<4;i++)
        {
            dfs(board,vis,x+mov[i],y+mov[i+1],isbound);
        }


    }

    void solve(vector<vector<char>>& board)
    {

      int m=board.size();
      int n=board[0].size();

      vector<vector<bool>>vis(m,vector<bool>(n,false));

      // top & btm row

      for(int j=0;j<n;j++)
      {
        if(board[0][j]=='O' && !vis[0][j])
        dfs(board,vis,0,j,true);
        if(board[m-1][j]=='O' && !vis[m-1][j])
        dfs(board,vis,m-1,j,true);

      }

      // left & rght col
      for(int i=0;i<m;i++)
      {
        if(board[i][0]=='O' && !vis[i][0])
        dfs(board,vis,i,0,true);
        if(board[i][n-1]=='O' && !vis[i][n-1])
        dfs(board,vis,i,n-1,true);

      }

      for(int i=0;i<m;i++)
      {

         for(int j=0;j<n;j++)
         {
            if(board[i][j]=='O' && !vis[i][j])
            {
                board[i][j]='X';
            }
         }

      }


    }
};
//
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        ROWS = board.size();
        COLS = board[0].size();
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1)
                    DFS(board, i, j);
            }
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'E')
                    board[i][j] = 'O';
            }
        }
    }

private:
    int ROWS, COLS;
    void DFS(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] != 'O') return;
        board[i][j] = 'E';
        if (j < COLS - 1) DFS(board, i, j + 1);
        if (i < ROWS - 1) DFS(board, i + 1, j);
        if (j > 0) DFS(board, i, j - 1);
        if (i > 0) DFS(board, i - 1, j);
    }
};