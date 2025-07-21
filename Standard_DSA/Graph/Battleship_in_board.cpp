class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<bool>>&vis,int x,int y)
    {

 if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y]=='.' || vis[x][y])
 {
    return;
 }

 vis[x][y]=true;

 dfs(board,vis,x-1,y);
 dfs(board,vis,x,y+1);
 dfs(board,vis,x+1,y);
 dfs(board,vis,x,y-1);

    }
    int countBattleships(vector<vector<char>>& board)
    {

        int m=board.size();
        int n=board[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int ans=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='X' && !vis[i][j])
                {
                    dfs(board,vis,i,j);
                    ans+=1;
                }
            }
        }

        return ans;

    }
};