class TicTacToe {
public:
    vector<vector<int>>board;
    int n;

    TicTacToe(int n)
    {
        board.assign(n,vector<int>(n,0));
        this->n=n;

    }

    int move(int row, int col, int player)
    {
        board[row][col]=player;

        if(checkCol(col,player) || checkRow(row,player) || (row==col && checkDiagonal(player)) || (row==n-col-1 && checkAntiDiagonal(player)))
        {
            return player;
        }

        // No one wins
        return 0;

    }

    bool checkDiagonal(int player)
    {
        for(int row=0;row<n;row++)
        {
            if(board[row][row]!=player)
            return false;
        }

        return true;
    }

    bool checkAntiDiagonal(int player)
    {
        for(int row=0;row<n;row++)
        {
            if(board[row][n-row-1]!=player)
            return false;
        }
        return true;
    }

    bool checkCol(int col,int player)
    {
        for(int row=0;row<n;row++)
        {
            if(board[row][col]!=player)
            return false;
        }
        return true;
    }

    bool checkRow(int row,int player)
    {
        for(int col=0;col<n;col++)
        {
            if(board[row][col]!=player)
            return false;
        }

        return true;
    }


};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
class TicTacToe {
public:
    vector<int>rows;
    vector<int>cols;

    int diagonal;
    int antiDiagonal;


    TicTacToe(int n)
    {
        rows.assign(n,0);
        cols.assign(n,0);
        diagonal=0;
        antiDiagonal=0;


    }

    int move(int row, int col, int player)
    {
       int currentPlayer=(player==1)?1:-1;

       // update currentPlayer in rows and cols arrays
       rows[row]+=currentPlayer;
       cols[col]+=currentPlayer;

       // update diagonal
       if(row==col)
       {
         diagonal+=currentPlayer;
       }

       // update anti diagonal
       if(col==(cols.size()-row-1))
       {
        antiDiagonal+=currentPlayer;
       }

       int n=rows.size();

       // check if the current player wins
       if(abs(rows[row])==n || abs(cols[col])==n || abs(diagonal)==n || abs(antiDiagonal)==n)
       return player;

       // No one wins
       return 0;
    }



};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */