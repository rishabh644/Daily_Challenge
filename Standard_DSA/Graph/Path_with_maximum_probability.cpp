
class Cmp
{
    public:
    bool operator()(pair<int,double>&a,pair<int,double>&b)
    {
        return b.second<a.second;
    }

};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)
    {

        vector< vector< pair<int,double> > >adjl(n);
        double max_double=numeric_limits<double>::max();
        for(int e=0;e<edges.size();e++)
        {
           int u=edges[e][0];
           int v=edges[e][1];
           double cost=-1*log(succProb[e]);
           adjl[u].push_back({v,cost});
           adjl[v].push_back({u,cost});
        }

        vector<double>distance(n,max_double);

        distance[start]=0;

        priority_queue<pair<int,double>,vector<pair<int,double>>,Cmp>pq;



       pq.push({start,0});

       pair<int,double>pr;


       while(!pq.empty())
       {
           pr=pq.top();
           pq.pop();
           int u=pr.first;
           double c=pr.second;
           if(distance[u]<c)
           continue;
           for(auto adjV:adjl[u])
           {
               int av=adjV.first;
               double cs=adjV.second;
               if(distance[av]>c+cs)
               {

                  distance[av]=c+cs;
                  pq.push({av,c+cs});
               }

           }
       }

       if(distance[end]!=max_double)
       {
          double res=exp(-distance[end]);
          return res;
       }
       else
       {
        return 0;
       }

    }
};