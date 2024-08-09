class CMP
{
    public:

     bool operator()(pair<int,int>a,pair<int,int>b)
     {
        return b.second<a.second;
     }


};

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here

        vector<int>distance(V,INT_MAX);

        distance[S]=0;


        priority_queue< pair<int,int>,vector<pair<int,int>>,CMP >pq;

        pq.push({S,0});

        while(!pq.empty())
        {

            pair<int,int>ve=pq.top();
            pq.pop();

            int v=ve.first;
            int d=ve.second;

            if(distance[v]<d)
            continue;

            for(auto e:adj[v])
            {
                int av=e[0];
                int wt=e[1];
                if(distance[av]>(d+wt))
                {
                    distance[av]=d+wt;
                    pq.push({av,distance[av]});
                }
            }

        }

        return distance;

    }
};