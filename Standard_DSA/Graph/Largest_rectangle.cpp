class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix)
    {

        int m=matrix.size();
        int n=matrix[0].size();

        int ans=0;

        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(matrix[row][col]!=0 && row>0)
                {
                    matrix[row][col]+=matrix[row-1][col];
                }
            }

            vector<int>currRow=matrix[row];
            sort(currRow.begin(),currRow.end(),greater());

            for(int i=0;i<n;i++)
            {
                ans=max(ans,currRow[i]*(i+1));
            }

        }

        return ans;
    }
};
////////////
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix)
    {

        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>prevRow=vector(n,0);
        int ans=0;

        for(int row=0;row<m;row++)
        {
            vector<int>currRow=matrix[row];

            for(int col=0;col<n;col++)
            {
               if(currRow[col]!=0)
               {
                  currRow[col]+=prevRow[col];
               }
            }



        vector<int>sortedRow=currRow;

        sort(sortedRow.begin(),sortedRow.end(),greater());

        for(int i=0;i<n;i++)
        {
            ans=max(ans,sortedRow[i]*(i+1));
        }

        prevRow=currRow;

        }

        return ans;
    }

};