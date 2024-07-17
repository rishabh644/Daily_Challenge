class Solution {

public:
static bool my_cmp(vector<int>&a,vector<int>&b)
{
    return a[1]<b[1];
}

public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

      vector<vector<int>>p;
      int n=positions.size();

      for(int i=0;i<n;i++)
      {
        p.push_back({i,positions[i]});
      }

      sort(p.begin(),p.end(),my_cmp);



    stack<int>st;



    for(auto pr:p)
    {
        if(directions[pr[0]]=='R')
        st.push(pr[0]);
        else
        {
        while(!st.empty())
        {
            if(healths[st.top()]<healths[pr[0]])
            {
                healths[st.top()]=0;
                st.pop();
                healths[pr[0]]-=1;
            }
            else if(healths[st.top()]>healths[pr[0]])
            {
                healths[st.top()]-=1;
                healths[pr[0]]=0;
                break;
            }
            else
            {   healths[st.top()]=0;
                st.pop();
                healths[pr[0]]=0;
                break;
            }
        }

        }



    }

    vector<int>uh;

    for(auto h:healths)
    {
        if(h>0)
        uh.push_back(h);
    }

    return uh;
    }
};