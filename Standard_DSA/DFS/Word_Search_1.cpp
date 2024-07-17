vector<pair<int,int>>mov={{0,-1},{0,1},{-1,0},{1,0}};

bool dfs(vector<vector<char>>& board,vector<vector<bool>>&visited,int idx,string target,int i,int j,int m,int n)
{
    if(idx==target.size())
    {
        return true;

    }


    if(i<0 || j<0 || i>=m || j>=n || visited[i][j]==true || board[i][j]!=target[idx])
    return false;

    visited[i][j]=true;



    int x,y;

    for(auto pr:mov)
    {

       x=i+pr.first;
       y=j+pr.second;

       if(dfs(board,visited,idx+1,target,x,y,m,n))
       return true;

    }

   visited[i][j]=false;
   return false;
}

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {


     vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));

     int m=board.size();
     int n=board[0].size();

     int i,j;


     for(i=0;i<m;i++)
     {
        for(j=0;j<n;j++)
        {

            if(dfs(board,visited,0,word,i,j,m,n))
            {
                return true;
            }

        }
     }

     return false;


    }
};