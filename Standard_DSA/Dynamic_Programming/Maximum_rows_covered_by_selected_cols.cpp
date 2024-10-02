class Solution {
public:



    void max_select(vector<vector<int>>& mat,int i,int& mask,int& cols,int& ans)
    {
        if(cols==0)
        {
           int m=mat.size();
           int n=mat[0].size();

           int cvrd=0;

           for(int i=0;i<m;i++)
           {
               bool cv=true;
               for(int j=0;j<n;j++)
               {


                    if(mat[i][j]==1 && ((mask>>(n-j-1))&1)==1)
                    {
                        cv=false;
                        break;
                    }

               }
               if(cv)
               cvrd+=1;

           }

          ans=max(ans,cvrd);

           return;
        }
        int n=mat[0].size();
        if(i==n)
        return;

        // select i column
        int shift=1<<(n-i-1);

        mask=mask^shift;
        cols-=1;
        max_select(mat,i+1,mask,cols,ans);
        mask=mask^shift;
        cols+=1;
        // don't select i column

        max_select(mat,i+1,mask,cols,ans);


    }

    int maximumRows(vector<vector<int>>& mat, int cols)
    {

       int ans=0;
       int n=mat[0].size();

       int mask=(1<<n) - 1;
       int i=0;
       max_select(mat,i,mask,cols,ans);

       return ans;

    }


};