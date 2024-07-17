int findTheWinner(int n, int k) {

     int live=n; // Number of people still in the game

     vector<bool>mark(n,true); // mark the live/dead

     int i=0; // starting index

     int prev=0; // prev person considered

     int visited=0;

     while(live>1)
     {

        visited=0;

        while(visited<k)
        {

            if(mark[i]==true)
            visited+=1;

            prev=i;
            i=(i+1)%n;
        }

        mark[prev]=false;
        live-=1;

     }

     for(i=0;i<n;i++)
     {

        if(mark[i])
        return i+1;

     }

      return 0;

    }

// Time complexity is O(N*N*K)


int findTheWinner(int n, int k) {

     // Initialize vector of N friends, labeled from 1-N

     vector<int>circle;

     for(int i=1;i<=n;i++){
        circle.push_back(i);
     }

    // Maintain the index of the friend to start the count on
    int startIndex=0;

    // Perform eliminations while there is more than 1 friend left

    while(circle.size() > 1)
    {
         // Calculate the index of the friend to be removed
         int removalIndex=(startIndex+k-1)%circle.size();

         // Erase the friend at removalIndex

         circle.erase(circle.begin()+removalIndex);

         // Update startIndex for the next round

         startIndex=removalIndex;

    }

    return circle.front();

}

// Time Complexity : O(N^2)




class Solution {
public:
    int findTheWinner(int n, int k) {


     queue<int>circle;

     for(int i=1;i<=n;i++)
     {
        circle.push(i);
     }


     // Perform eliminations while more than 1 player remains

     while(circle.size() >1 )
     {

       // Process the first k-1 friends without eliminating them
       for(int i=0;i<(k-1);i++)
       {
           circle.push(circle.front());
           circle.pop();
       }

       // Eliminate the k-th friend
       circle.pop();

     }

     return circle.front();

     }

};

// Time Complexity : o(N *K);
