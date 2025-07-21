class Solution {
private:
    // box size
    int  n=3;
    // row size
    int N=n*n;

    int **rows;
    int **columns;
    int **boxes;
    vector<vector<char>>board;
    bool sodoku_solved=false;

public:

    bool could_place(int d,int row,int col)
    {

        int idx=(row/n)*n+(col/n);
        return rows[row][d]+columns[col][d]+boxes[idx][d]==0;

    }

    void place_number(int d,int row,int col)
    {
        int idx=(row/n)*n+ col/n;
        rows[row][d]++;
        columns[col][d]++;
        boxes[idx][d]++;
        board[row][col]=(char)(d+'0');
    }

    void remove_number(int d,int row,int col)
    {
        int idx=(row/n)*n +col/n;
        rows[row][d]--;
        columns[col][d]--;
        boxes[idx][d]--;
        board[row][col]='.';
    }

    void place_next_numbers(int row,int col)
    {

       if( (col==N-1) && (row==N-1) )
       {
        sodoku_solved=true;
       }
       // if not yet
       else
       {
          if(col==N-1)
          backtrack(row+1,0);
          else
          backtrack(row,col+1);
       }

    }

    void backtrack(int row,int col)
    {
        if(board[row][col]=='.')
        {
            // iterate over all numbers from 1 to 9
            for(int d=1;d<10;d++)
            {
               if(could_place(d,row,col))
               {

                 place_number(d,row,col);
                 place_next_numbers(row,col);

                 // If sudoku is solved, there is no need to backtrack
                 // since the single unique solution is promised

                 if(!sodoku_solved)
                 remove_number(d,row,col);
               }

            }
        }
        else
        {
            place_next_numbers(row,col);
        }
    }

    void solveSudoku(vector<vector<char>>& board)
    {

      this->board=board;
      rows=new int *[N];
      columns=new int *[N];

      boxes=new int *[N];

      for(int i=0;i<N;i++)
      {
          rows[i]=new int[N+1]();
          columns[i]=new int[N+1]();
          boxes[i]=new int[N+1]();
      }

      // init rows,columns, and boxes

      for(int i=0;i<N;i++)
      {
         for(int j=0;j<N;j++)
         {
             char num=board[i][j];
             if(num!='.')
             {
                int d=num-'0';
                place_number(d,i,j);
             }

         }

      }

      backtrack(0,0);
      board=this->board;

    }
};