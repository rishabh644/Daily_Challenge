int minMeetingRooms(vector<vector<int>>& intervals)
    {

         vector<int>st;
         vector<int>ed;

         for(int i=0;i<intervals.size();i++)
         {
            st.push_back(intervals[i][0]);
            ed.push_back(intervals[i][1]);
         }

         sort(st.begin(),st.end());
         sort(ed.begin(),ed.end());

         int n=intervals.size();
         int i=0;
         int j=0;

         int rp=0;

         while(i<n && j<n)
         {

           if(st[i]<ed[j])
           {
            i++;
            rp++;
           }
           else
           {
             j++;
             i++;
           }

         }


         return rp;

    }

///////////////////////////////-----Above was without priority queue----/////////////////////////////////////

class Cmp
{
    public:
    bool operator()(int& a,int& b)
    {
        return a>b;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals)
    {

      // Check for the base case. If there are no intervals, return 0
      if(intervals.size()==0)
      return 0;

      //Min heap

      priority_queue<int,vector<int>,Cmp>pq;

      sort(intervals.begin(),intervals.end());

      // Add the first meeting
      pq.push(intervals[0][1]);

      //Iterate over remaining intervals

      for(int i=1;i<intervals.size();i++)
      {

          // If the room due to free up the earliest is free,assign that room to this meeting.

          if(intervals[i][0]>=pq.top())
          pq.pop();

          // If a new room is to be assigned, then also we add to the heap
          // If an old room is allocated, then also we have to add to the heap with updated end time

          pq.push(intervals[i][1]);
      }

      return pq.size();

    }
};
//////////////////-------------//////////////-----------//////////---