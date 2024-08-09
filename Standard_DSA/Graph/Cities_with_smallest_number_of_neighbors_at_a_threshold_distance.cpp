class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
      // Adjacency list to store the graph
      vector<vector<pair<int,int>>>adjacencyList(n);
      // Matrix to store shortest path distances from each city

      vector<vector<int>>shortestPathMatrix(n,vector<int>(n,INT_MAX));

      // Initialize adjacency list and shortest path matrix

      for(int i=0;i<n;i++){
        shortestPathMatrix[i][i]=0; // Distance to itself is zero
      }

      // Populate the adjacency list with edges

      for(const auto& edge:edges)
      {

         int start=edge[0];
         int end=edge[1];
         int weight=edge[2];
         adjacencyList[start].emplace_back(end,weight);
         adjacencyList[end].emplace_back(start,weight); // For undirected graph

      }

      // Compute shortest paths from each city using Dijkstra's algorithm

      for(int i=0;i<n;i++)
      {
        dijkstra(n,adjacencyList,shortestPathMatrix[i],i);
      }

      // Find the city with the fewest number of reachable cities within the
      // distance threshold

      return getCityWithFewestReachable(n,shortestPathMatrix,distanceThreshold);

    }

    void dijkstra(int n,const vector<vector<pair<int,int>>>&adjacencyList,vector<int>&
    shortestPathDistances,int source)
    {
      //Priority queue to process nodes with the smallest distance first

      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >priorityQueue;

      priorityQueue.emplace(0,source);

      fill(shortestPathDistances.begin(),shortestPathDistances.end(),INT_MAX);

      shortestPathDistances[source]=0; // Distance to source itself is zero

      // Process nodes in priority order

      while(!priorityQueue.empty())
      {
        auto [currentDistance,currentCity]=priorityQueue.top();
        priorityQueue.pop();

        if(currentDistance>shortestPathDistances[currentCity]){
            continue;
        }

        // Update distances to neighboring cities

        for(const auto& [neighborCity,edgeWeight]:adjacencyList[currentCity])
        {
            if(shortestPathDistances[neighborCity]>currentDistance+edgeWeight)
            {

              shortestPathDistances[neighborCity]=currentDistance+edgeWeight;

              priorityQueue.emplace(shortestPathDistances[neighborCity],neighborCity);

            }

        }



      }




    }


    // Determine the city with the fewest number of reachable cities within the
    // distance threshold

    int getCityWithFewestReachable(int n,const vector<vector<int>>&shortestPathMatrix,
    int distanceThreshold)
    {
        int cityWithFewestReachable=-1;
        int fewestReachableCount=n;

        // Count number of cities reachablw within the distance threshold
        // for each city


        for(int i=0;i<n;i++)
        {
             int reachableCount=0;

             for(int j=0;j<n;j++)
             {

                 if(i==j)
                 {
                    continue;
                 } // Skip self

                 if(shortestPathMatrix[i][j]<=distanceThreshold)
                 {
                    reachableCount++;
                 }
             }

             if(reachableCount<=fewestReachableCount)
             {
                fewestReachableCount=reachableCount;
                cityWithFewestReachable=i;
             }


        }

        return cityWithFewestReachable;


    }


};

////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    const int INF=1e9+7;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
       // Matrix to store shortest path distances from each city

       vector<vector<int>>shortestPathMatrix(n,vector<int>(n,INF));

       // Initialize shortest path matrix

       for(int i=0;i<n;i++)
       {
         shortestPathMatrix[i][i]=0; // Distance to itself is zero
       }

       // Populate the matrix with initial edge weights

       for(const auto& edge:edges){
        int start=edge[0];
        int end=edge[1];
        int weight=edge[2];

        shortestPathMatrix[start][end]=weight;
        shortestPathMatrix[end][start]=weight; // for undirected graph

       }

       // Compute shortest paths from each city using Bellman-Ford algorithm

       for(int i=0;i<n;i++)
       {
        bellmanFord(n,edges,shortestPathMatrix[i],i);
       }

       // Find the city with the fewest number of rachable cities within the
       // distance threshold

       return getCityWithFewestReachable(n,shortestPathMatrix,distanceThreshold);


    }
 private:
   void bellmanFord(int n,const vector<vector<int>>&edges,vector<int>&shortestPathDistances,int source)
   {

     // Initialize distances from the source

     fill(shortestPathDistances.begin(),shortestPathDistances.end(),INF);
     shortestPathDistances[source]=0; // Distance to source itself is zero

     // Relax edges up to n-1 times

     for(int i=1;i<n;i++)
     {
       for(const auto& edge:edges)
       {
             int start=edge[0];
             int end=edge[1];
             int weight=edge[2];

             // Update shortest path distances if a shorter path is found

             if(shortestPathDistances[start]!=INF && shortestPathDistances[start]+weight<shortestPathDistances[end])
             {
                shortestPathDistances[end]=shortestPathDistances[start]+weight;
             }
             if(shortestPathDistances[end]!=INF && shortestPathDistances[end]+weight<shortestPathDistances[start])
             {
                shortestPathDistances[start]=shortestPathDistances[end]+weight;
             }

       }


     }


   }

   int getCityWithFewestReachable(int n,const vector<vector<int>>& shortestPathMatrix,int distanceThreshold)
   {

       int cityWithFewestReachable=-1;
       int fewestReachableCount=n;

       //Count number of cities reachable within the distance threshold for
       // each city

       for(int i=0;i<n;i++)
       {
          int reachableCount=0;

          for(int j=0;j<n;j++)
          {
                  if(i==j)
                  continue;

                  if(shortestPathMatrix[i][j]<=distanceThreshold)
                  reachableCount++;
          }

          // Uodate the city with the fewest reachable cities

       if(reachableCount<=fewestReachableCount)
       {
         fewestReachableCount=reachableCount;
         cityWithFewestReachable=i;
       }

       }

       return cityWithFewestReachable;

   }

};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
