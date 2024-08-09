class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
       stack<int>st;
       int n=heights.size();
       vector<int>pl(n,0);
       vector<int>nl(n,0);
       for(int i=0;i<n;i++)
       {
           while(!st.empty() && heights[st.top()]>=heights[i])
           {
            st.pop();
           }
           pl[i]=st.empty()?-1:st.top();

           st.push(i);
       }
       while(!st.empty())
       st.pop();

       for(int i=n-1;i>=0;i--)
       {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }

            nl[i]=st.empty()?n:st.top();

            st.push(i);
       }

        int largestarea=0;

        for(int i=0;i<n;i++)
        {

            largestarea=max(largestarea,(nl[i]-pl[i]-1)*heights[i]);

        }

        return largestarea;
    }
};