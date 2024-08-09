class Solution {
private:
    int largestareaHistogram(int n,vector<int>&colh)
    {
        vector<int>pl;
        vector<int>nl;
        stack<int>st;
        for(int i=0;i<n;i++)
        {
           while(!st.empty() && colh[st.top()]>=colh[i])
           {
            st.pop();
           }
           if(!st.empty())
           {
              pl[i]=st.top();
           }
           else
           {
            pl[i]=-1;
           }
           st.push(i);
        }
        while(!st.empty())
        st.pop();
        for(int i=n-1;i>=0;i--)
        {
           while(!st.empty() && colh[st.top()]>=colh[i])
           {
            st.pop();
           }
           if(!st.empty())
           {
              nl[i]=st.top();
           }
           else
           {
            nl[i]=n;
           }
           st.push(i);
        }
        int area=0;
        for(int i=0;i<n;i++)
        {
            area=max(area,colh[i]*(nl[i]-pl[i]-1));
        }

        return area;

    }

public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {

       int m=matrix.size();
       int n=matrix[0].size();
       vector<int>colh(n,0);
       int area=0;
       for(int i=0;i<m;i++)
       {
          for(int j=0;j<n;j++)
          {
             if(matrix[i][j]=='1')
             {
                    colh[j]+=1;
             }
             else
             {
                colh[j]=0;
             }
          }
          area=max(area,largestareaHistogram(n,colh));
       }

        return area;
    }


};