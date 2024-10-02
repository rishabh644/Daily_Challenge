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

    int findMinArrowShots(vector<vector<int>>& points)
    {
        if(points.size()<=1)
        return points.size();

        priority_queue<int,vector<int>,Cmp>pq;

        sort(points.begin(),points.end());

        pq.push(points[0][1]);
        int cnt=1;
        for(int i=1;i<points.size();i++)
        {

            if(points[i][0]>pq.top())
            {
                pq.pop();
                cnt+=1;
                pq.push(points[i][1]);
            }
            else
            {
                if(points[i][1]<pq.top())
                {
                    pq.pop();
                    pq.push(points[i][1]);
                }
            }

        }



        return cnt;
    }
};

// Above is like finding number of intervals which don'e have a  single common point.
// If n interval have a single common point we merge that into a single interval.
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

    int findMinArrowShots(vector<vector<int>>& points)
    {

        if(points.size()==0)
        return 0;

        sort(points.begin(),points.end(),[](const vector<int>&o1,const vector<int>&o2)
        {
            return (o1[1]<o2[1]);
        });

        int arrows=1;

        int xStart,xEnd,firstEnd=points[0][1];

        for(auto p:points)
        {
            xStart=p[0];
            xEnd=p[1];

            // If the current ballon starts after the end of another one,
            // one needs one more arrow
            if(firstEnd<xStart)
            {
                arrows++;
                firstEnd=xEnd;
            }

        }

        return arrows;
    }
};