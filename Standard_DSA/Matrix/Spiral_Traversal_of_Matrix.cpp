class Solution {
public:
    void my_print(vector<vector<int>>& matrix,int i,int j,int m,int n,vector<int>&ans)
    {

       // Base Case if m is 0 or n is 0
       if(m<=0 || n<=0)
       return;

       // Add elements of first row
       for(int c=j;(c-j+1)<=n;c++)
       {
        ans.push_back(matrix[i][c]);
       }

       // Add elements of last column
       for(int r=i+1;(r-i+1)<=(m-1);r++)
       {
        ans.push_back(matrix[r][j+n-1]);
       }
       // If there are more than one row
       if(m>1){
       for(int c=j+(n-1);c>=j;c--)
       {
        ans.push_back(matrix[i+m-1][c]);
       }}
       // If there are more than one column
       if(n>1){
       for(int r=i+m-2;r>i;r--)
       {
        ans.push_back(matrix[r][j]);
       } }

       my_print(matrix,i+1,j+1,m-2,n-2,ans);

    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {

     int m=matrix.size();
     int n=matrix[0].size();

     vector<int>ans;

     // Start the recursive function
     my_print(matrix,0,0,m,n,ans);

     return ans;

    }
};