class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {

        vector<vector<int>>ans;

        int start=newInterval[0];
        int end=newInterval[1];
        int i=0,j;
        int n=intervals.size();

        if(n==0)
        {
            return {{start,end}};
        }
        if(intervals[n-1][1]<start)
        {
            intervals.push_back({start,end});
            return intervals;
        }
        while(i<n)
        {
            int a=intervals[i][0];
            int b=intervals[i][1];

            if(b<start)
            {
                ans.push_back({a,b});
            }
            else
            {
                start=min(a,start);
                j=i;
                while(j<n && end>=intervals[j][0])
                {
                    end=max(end,intervals[j][1]);
                    j+=1;
                }
                ans.push_back({start,end});
                start=INT_MAX;
                i=j;
                continue;
            }
            i=i+1;
        }

        return ans;
    }
};
//////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;

        // Case 1: no overlapping case before the merge intervals
        // Compare ending point of intervals to starting point of newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        // Case 2: overlapping case and merging of intervals
        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        // Case 3: no overlapping of intervals after newinterval being merged
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
/////////////////////////////////////////////////////////////////////////////////////
