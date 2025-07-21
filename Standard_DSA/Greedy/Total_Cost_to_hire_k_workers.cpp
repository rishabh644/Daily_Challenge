class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cs)
    {

       long long cost=0;
       int minval;
       int minind;
       while(k>0)
       {

          if(costs.size()>cs)
          {

            minval=costs[0];
            minind=0;

            for(int i=0;i<cs;i++)
            {
                if(costs[i]<minval)
                {
                    minval=costs[i];
                    minind=i;
                }
            }

            for(int j=costs.size()-cs;j<costs.size();j++)
            {
                if(costs[j]<minval)
                {
                    minval=costs[j];
                    minind=j;
                }
            }

          }
          else
          {

            minval=costs[0];
            minind=0;

            for(int i=0;i<costs.size();i++)
            {
                if(costs[i]<minval)
                {
                    minval=costs[i];
                    minind=i;
                }
            }

          }


          cost+=minval;
          vector<int>temp;

          for(int i=0;i<costs.size();i++)
          {
              if(i==minind)
              continue;

              temp.push_back(costs[i]);

          }
          costs=temp;
          k-=1;

       }

       return cost;

    }
};
/////////////////////////////////////////////---------------------////////////////////////
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cs)
    {

      long long ans=0;

      priority_queue<int,vector<int>,greater<int>>left_min;
      priority_queue<int,vector<int>,greater<int>>right_min;

      int n=costs.size();

      for(int i=0;i<cs;i++)
      {
        left_min.push(costs[i]);
      }

      for(int j=max(cs,n-cs);j<n;j++)
      {
        right_min.push(costs[j]);
      }

      int next_left=cs;
      int next_right=max(cs,n-cs)-1;


      while(k>0)
      {

          if(right_min.empty() ||(!left_min.empty() && left_min.top()<=right_min.top())   ) {
            ans+=left_min.top();
            left_min.pop();
            if(next_left<=next_right)
            {
               left_min.push(costs[next_left]);
               next_left++;
            }
          }
          else
          {
            ans+=right_min.top();
            right_min.pop();

            if(next_left<=next_right)
            {
               right_min.push(costs[next_right]);
               next_right--;
            }

          }
          k-=1;

      }

      return ans;

    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cs)
    {

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;


        int n=costs.size();

        for(int i=0;i<cs;i++)
        {
            pq.push({costs[i],0});
        }

        for(int j=max(cs,n-cs);j<n;j++)
        {
            pq.push({costs[j],1});
        }

        long answer=0;
        int nextHead=cs;
        int nextTail=costs.size()-1-cs;

        for(int i=0;i<k;i++)
        {
            pair<int,int>curWorker=pq.top();
            pq.pop();

            int curCost=curWorker.first;
            int curSectionId=curWorker.second;

            answer+=curCost;

            if(nextHead<=nextTail)
            {
                if(curSectionId==0)
                {
                    pq.push({costs[nextHead],0});
                    nextHead++;
                }
                else
                {
                    pq.push({costs[nextTail],1});
                    nextTail--;
                }
            }

        }

        return answer;

    }
};