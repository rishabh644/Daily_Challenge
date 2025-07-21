class Solution {
  public:

    int myboundarysum(vector<vector<int>> &matrix,int ind,int col)
    {
        int sm=0;

        int j=ind;

        while(j<ind+col)
        {
            sm+=matrix[ind][j];
            j+=1;
        }

        int i=ind+1;

        while(i<ind+col)
        {
            sm+=matrix[i][ind+col-1];
            i+=1;
        }

        j=ind+col-2;

        while(j>=ind)
        {
            sm+=matrix[ind+col-1][j];
            j-=1;
        }

        i=ind+col-2;

        while(i>ind)
        {
            sm+=matrix[i][ind];
            i-=1;
        }

        return sm;

    }
    vector<int> boundarySum(int n, vector<vector<int>> &matrix)
    {
        // code here

        vector<int>ans;

        int i=0,j=0;

        int col=matrix[0].size();

        while(col>0)
        {
            int sm=myboundarysum(matrix,i,col);
            ans.push_back(sm);
            i+=1;
            col-=2;
        }

        return ans;




    }
};