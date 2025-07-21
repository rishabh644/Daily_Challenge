class Solution {
public:
    int minGroups(vector<vector<int>>& intervals)
    {

       vector<int>start_time;
       vector<int>end_time;

       for(int i=0;i<intervals.size();i++)
       {

          start_time.push_back(intervals[i][0]);
          end_time.push_back(intervals[i][1]);

       }

       sort(start_time.begin(),start_time.end());
       sort(end_time.begin(),end_time.end());

       int cnt=0;
       int i=0;
       int j=0;

       int n=intervals.size();

       while(i<n)
       {
          if(start_time[i]<=end_time[j])
          {

            cnt+=1;
          }
          else
          {

            j++;
          }

          i+=1;

       }
       return cnt;



    }
};
///////////////////


class Solution {
public:
    int minGroups(vector<vector<int>>& intervals)
    {

        vector<pair<int,int>>intervalsWithEnd;

        for(vector<int>interval:intervals)
        {
            intervalsWithEnd.push_back({interval[0],1});
            intervalsWithEnd.push_back({interval[1]+1,-1});
        }

        sort(intervalsWithEnd.begin(),intervalsWithEnd.end());

        int concurrentIntervals=0;
        int maxConcurrentIntervals=0;

        for(auto p:intervalsWithEnd)
        {
           concurrentIntervals+=p.second;
           maxConcurrentIntervals=max(maxConcurrentIntervals,concurrentIntervals);
        }


        return maxConcurrentIntervals;

    }
};

/////////////////
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals)
    {

         map<int,int>pointToCount;

         // Mark the starting and ending points in the map

         for(vector<int>interval:intervals)
         {
            pointToCount[interval[0]]++;
            pointToCount[interval[1]+1]--;
         }

         int concurrentIntervals=0;
         int maxConcurrentIntervals=0;

         // Iterate over the numbers in ascending order

         for(pair<int,int>p:pointToCount)
         {

              // Add the currently active intervals
              concurrentIntervals+=p.second;

              // Update the maximum active intervals at any time

              maxConcurrentIntervals=max(maxConcurrentIntervals,concurrentIntervals);

         }


         return maxConcurrentIntervals;

    }
};