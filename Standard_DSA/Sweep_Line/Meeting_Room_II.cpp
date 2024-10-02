
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
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals)
    {
        int end=1e6+2;

        vector<int>vec(end,0);

        for(auto itr:intervals)
        {
            vec[itr[0]]++;
            vec[itr[1]]--;
        }

        int mxrm=0;
        int rm=0;

        for(int i=0;i<end;i++)
        {
            rm=rm+vec[i];
            mxrm=max(mxrm,rm);

        }

        return mxrm;


    }
};
/////////////////
class Solution {
public:

    int minMeetingRooms(vector<vector<int>>& intervals)
    {
        if(intervals.size()==0)
        return 0;

        vector<int>start(intervals.size());

        vector<int>end(intervals.size());

        for(int i=0;i<intervals.size();i++)
        {
           start[i]=intervals[i][0];
           end[i]=intervals[i][1];

        }

        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int startpointer=0,endpointer=0;

        int usedRooms=0;

        // Iterate over intervals

        while(startpointer < intervals.size())
        {

            if(start[startpointer]>=end[endpointer])
            {
                usedRooms-=1;
                endpointer+=1;
            }

            usedRooms+=1;
            startpointer+=1;
        }

        return usedRooms;
    }
};