class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences)
    {


        int n=nums.size();

        vector<vector<int>>adjl(n+1);

        vector<int>indegree(n+1,0);

        for(auto sq:sequences)
        {
            for(int i=0;i<sq.size();i++)
            {
                for(int j=i+1;j<sq.size();j++)
                {
                    indegree[sq[j]]++;
                    adjl[sq[i]].push_back(sq[j]);
                }
            }

        }

        queue<int>qu;

        for(int i=1;i<=n;i++)
        {
            if(indegree[i]==0)
            qu.push(i);
        }

        vector<int>ans;

        while(!qu.empty())
        {
           if(qu.size()>=2)
           return false;

           int ver=qu.front();
           ans.push_back(ver);
           qu.pop();

           for(auto adjv:adjl[ver])
           {
              indegree[adjv]-=1;
              if(indegree[adjv]==0)
              {
                qu.push(adjv);
              }
           }

        }

        if(nums.size()>ans.size())
        return false;

        return true;

    }
};
//////////////////////////////////////////////////
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences)
    {


        int n=nums.size();

        vector<vector<int>>adjl(n+1);

        vector<int>indegree(n+1,0);

        for(auto sq:sequences)
        {
            for(int i=0;i<sq.size()-1;i++)
            {

                adjl[sq[i]].push_back(sq[i+1]);
                indegree[sq[i+1]]++;
            }

        }

        queue<int>qu;

        for(int i=1;i<=n;i++)
        {
            if(indegree[i]==0)
            qu.push(i);
        }

        vector<int>ans;

        while(!qu.empty())
        {
           if(qu.size()>=2)
           return false;

           int ver=qu.front();
           ans.push_back(ver);
           qu.pop();

           for(auto adjv:adjl[ver])
           {
              indegree[adjv]-=1;
              if(indegree[adjv]==0)
              {
                qu.push(adjv);
              }
           }

        }

        if(nums.size()==ans.size())
        return true;


        return false;

    }
};
////////////////////////////////////////////////////////////////////////////////////////////////
