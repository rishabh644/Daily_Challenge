You are given a floating-point number hour, representing the amount of time you have to reach the office. To commute to the office, you must take n trains in sequential order. You are also given an integer array dist of length n, where dist[i] describes the distance (in kilometers) of the ith train ride.

Each train can only depart at an integer hour, so you may need to wait in between each train ride.

For example, if the 1st train ride takes 1.5 hours, you must wait for an additional 0.5 hours before you can depart on the 2nd train ride at the 2 hour mark.
Return the minimum positive integer speed (in kilometers per hour) that all the trains must travel at for you to reach the office on time, or -1 if it is impossible to be on time.

Tests are generated such that the answer will not exceed 107 and hour will have at most two digits after the decimal point.

class Solution {
public:

    bool isPossible(vector<int>&dist,int spd,double hour)
    {
        double time_taken=0;
        int n=dist.size();

        for(int i=0;i<(n-1);i++)
        {
            time_taken+=ceil( (dist[i]*1.0)/spd );
        }

        time_taken+=(dist[n-1]*1.0/spd);

        return time_taken<=hour;

    }


    int minSpeedOnTime(vector<int>& dist, double hour) {

    int maxSpeed=*max_element(dist.begin(),dist.end())*100;

    int ans=-1;

    int minSpeed=1;

    while(minSpeed<=maxSpeed)
    {

         int spd=(minSpeed+maxSpeed)/2;

         if(isPossible(dist,spd,hour))
         {
            ans=spd;
            maxSpeed=spd-1;
         }
         else
         {
            minSpeed=spd+1;
         }

    }


    return ans;


    }
};