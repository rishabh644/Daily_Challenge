class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals)
    {

        int ed=1e6+1;

        vector<int>cnt(ed,0);

        for(auto intr:intervals)
        {

            cnt[intr[0]]++;
            cnt[intr[1]]--;

        }

        int mc=0;

        for(int s=0;s<ed;s++)
        {
            mc+=cnt[s];

            if(mc>1)
            return false;

        }

        return true;

    }
};
////
class Solution {
public:
    bool overlap(vector<int>& interval1,vector<int>& interval2)
    {
         return max(interval1[0],interval2[0])<min(interval1[1],interval2[1]);
    }

    bool canAttendMeetings(vector<vector<int>>& intervals)
    {

       if(intervals.empty())
       return true;

       // Note: C++ sort function automatically sorts a vector first
       // by the 1st element, then by the 2nd element and soon

       sort(intervals.begin(),intervals.end());

       for(size_t i=0;i<intervals.size()-1;i++)
       {
          if(intervals[i][1]>intervals[i+1][0])
          return false;
       }

       return true;

    }
};