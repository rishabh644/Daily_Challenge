class Cmp
{
    public:
      bool operator()(pair<int,int>&A,pair<int,int>&B)
      {
          return B.first<A.first;
      }

};

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend)
    {

        priority_queue<pair<int,int>,vector<pair<int,int>>,Cmp>pq;
        vector<vector<int>>vec;
        int n=times.size();
        for(int i=0;i<n;i++)
        {
            vec.push_back({times[i][0],i});
        }
        sort(vec.begin(),vec.end());
        vector<int>occupied(n,0);
        for(int i=0;i<n;i++)
        {

            int startt=vec[i][0];
            int index=vec[i][1];
            int endt=times[index][1];

            while(!pq.empty() && pq.top().first<=startt)
            {
                int chrind=pq.top().second;
                pq.pop();
                occupied[chrind]=0;
            }

            for(int j=0;j<n;j++)
            {

                if(occupied[j]==0)
                {
                    occupied[j]=1;
                    pq.push({endt,j});

                    if(index==targetFriend)
                    return j;

                    break;
                }

            }

        }

        return -1;
    }
};
//////////////////////////////////////////////-----------------Above was mine solution-----------------------///////////////////////////
class Cmp
{
    public:
      bool operator()(pair<int,int>&A,pair<int,int>&B)
      {
          return B.first<A.first;
      }
};

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend)
    {
        // priority queue of departure and index
        priority_queue<pair<int,int>,vector<pair<int,int>>,Cmp>departure;
        // vector of start time and index
        vector<vector<int>>arrival;
        int n=times.size();
        priority_queue<int,vector<int>,greater<int>>free;
        for(int i=0;i<n;i++)
        {
            arrival.push_back({times[i][0],i});
            free.push(i);
        }
        sort(arrival.begin(),arrival.end());
        for(int i=0;i<n;i++)
        {
            int startt=arrival[i][0];
            int index=arrival[i][1];
            int endt=times[index][1];
            while(!departure.empty() && departure.top().first<=startt)
            {
                int chrind=departure.top().second;
                departure.pop();
                free.push(chrind);
            }
            int occ=free.top();
            free.pop();
            if(index==targetFriend)
            return occ;
            departure.push({endt,occ});
        }
        return -1;
    }
};

////////////////////
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            leavingQueue;
        int targetArrival = times[targetFriend][0];

        sort(times.begin(), times.end());

        int nextChair = 0;  // Track next available chair number
        set<int> availableChairs;

        for (auto time : times) {
            int arrival = time[0];
            int leave = time[1];

            // Free up chairs based on current time
            while (!leavingQueue.empty() &&
                   leavingQueue.top().first <= arrival) {
                availableChairs.insert(leavingQueue.top().second);
                leavingQueue.pop();
            }

            int currentChair;
            // Assign chair from available set or increment new chair
            if (!availableChairs.empty()) {
                currentChair = *availableChairs.begin();
                availableChairs.erase(availableChairs.begin());
            } else {
                currentChair = nextChair++;
            }

            // Push current leave time and chair
            leavingQueue.push({leave, currentChair});

            // Check if it's the target friend
            if (arrival == targetArrival) return currentChair;
        }

        return 0;
    }
};