#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

static int count = 0;
void print_mat(vector<vector<int>>nmat)
{
    int i, j;
    for (i = 0; i < 8;i++)
   {
       for (j = 0; j < 8;j++)
       {
           cout << nmat[i][j] << " ";
       }
       cout << endl;
   }

   cout << "##########################################" << endl;
   //    exit(1);
   count += 1;
}

bool issafe(vector<vector<int>>nmat,int m,int n)
{

    int i=0, j=n;
    // column checking
    while (i < m)
    {
         if(nmat[i][j]==1)
             return false;
         i++;
    }
    // left upper diagonal
    int k = 1;
    i = m;
    j = n;
    while((i-k)>=0 && (j-k)>=0)
    {
       if(nmat[i-k][j-k]==1)
             return false;
       k += 1;
    }
    // right upper
    k = 1;
    i = m;
    j = n;
    while((i-k)>=0 && (j+k)<8)
    {
       if(nmat[i-k][j+k]==1)
             return false;
       k += 1;
    }


    return true;
}

void eight_queen(vector<vector<int>>nmat,int i,int j)
{

     while(j<8)
     {

         nmat[i][j] = 1;

        if(issafe(nmat,i,j))
        {
            if(i==7)
            {
                print_mat(nmat);
                nmat[i][j] = 0;
                return;
            }
            eight_queen(nmat, i + 1, 0);
        }
        nmat[i][j] = 0;
        j++;
     }
     return;
}




int main()
{

    vector<vector<int>> nmat(8, vector<int>(8, 0));


    eight_queen(nmat,0,0);
    cout <<"count "<<count<< endl;
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:

    int count=0;

    bool isSafe(int i,int j,vector<vector<int>>&board)
    {
       // check column

       int n=board.size();
       int k;

       for(k=0;k<i;k++)
       {
           if(board[k][j]==1)
               return false;
       }

       // left upper diagonal

        k=1;


       while((i-k)>=0 && (j-k)>=0)
       {
           if(board[i-k][j-k]==1)
               return false;

           k+=1;
       }
       k=1;
       while((i-k)>=0 && (j+k)<n)
       {
           if(board[i-k][j+k]==1)
               return false;
           k+=1;
       }

       return true;

    }

    void mytotalNQueens(int i,vector<vector<int>>&board)
    {
        int n=board.size();
        int k;
        for(k=0;k<n;k++)
        {
            if(isSafe(i,k,board))
            {
                if(i==n-1)
                    count+=1;

                board[i][k]=1;

                mytotalNQueens(i+1,board);
                board[i][k]=0;
            }

        }

    }

    int totalNQueens(int n)
    {

       vector<vector<int>>board(n,vector<int>(n,0));
       mytotalNQueens(0,board);

       return count;
    }
};
//////////////////////
class Solution {
public:

    int count=0;

    void mytotalNQueens(int row,int n,vector<bool>&cols,vector<bool>&d1,vector<bool>&d2)
    {
       if(row==n)
       {
           count++;
           return;
       }

       for(int col=0;col<n;col++)
       {
          if(cols[col] || d1[row-col+n-1] || d2[row+col])
              continue;

           // Mark the column and diagonal as occupied
           cols[col]=d1[row-col+n-1]=d2[row+col]=true;

           // Recurde to place the next queen

           mytotalNQueens(row+1,n,cols,d1,d2);

           // Backtrack and unmark the column and diagonals

           cols[col]=d1[row-col+n-1]=d2[row+col]=false;

       }



    }

    int totalNQueens(int n)
    {

       vector<bool>cols(n,false); // mark columns
        vector<bool>d1(2*n-1,false); // mark left diagonals (row-col)
        vector<bool>d2(2*n-1,false); // mark right diagonals (row+col)

        mytotalNQueens(0,n,cols,d1,d2);

        return count;

    }
};