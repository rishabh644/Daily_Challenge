class Solution {
public:

    int dfs(int v,vector<vector<int>>&adjl,vector<vector<int>>&visited)
    {
        visited[v][0]=1; //Mark the node as visited in the current path
        visited[v][1]=1;
        for(auto adjv:adjl[v])
        {
            if(visited[adjv][0]==1)
            {
               return -1;
            }
            else if(visited[adjv][0]==0)
            {
               int curr_d=dfs(adjv,adjl,visited);
               if(curr_d==-1)
               return -1;

               visited[v][1]=max(visited[v][1],1+curr_d);

            }
            else if(visited[adjv][0]==2)
            {
                visited[v][1]=max(visited[v][1],1+visited[adjv][1]);
            }

        }


        visited[v][0]=2;
        return visited[v][1];

    }

    int  topological_sort(vector<vector<int>>&adjl)
    {
        int N=adjl.size();
        vector<vector<int>>visited(N,vector<int>(2,0));

        int ans=0;
        for(int i=1;i<N;i++)
        {
            if(visited[i][0]==0)
            {   int cur=0;
                int curr_d=dfs(i,adjl,visited);

                if(curr_d==-1)
                return -1;

                ans=max(ans,curr_d);
            }
        }

        return ans;
    }

    int minimumSemesters(int n, vector<vector<int>>& relations)
    {


       vector<vector<int>>adjl(n+1);

       for(auto e:relations)
       {

           adjl[e[0]].push_back(e[1]);

       }

       int ans=topological_sort(adjl);

       return ans;




    }
};

///////////////////////
class Solution {
public:

    int dfs(int v,vector<vector<int>>&adjl,vector<vector<int>>&visited)
    {
        visited[v][0]=1; //Mark the node as visited in the current path
        visited[v][1]=1;
        for(auto adjv:adjl[v])
        {
            if(visited[adjv][0]==1)
            {
               return -1;
            }
            else if(visited[adjv][0]==0)
            {
               int curr_d=dfs(adjv,adjl,visited);
               if(curr_d==-1)
               return -1;

               visited[v][1]=max(visited[v][1],1+curr_d);

            }
            else if(visited[adjv][0]==2)
            {
                visited[v][1]=max(visited[v][1],1+visited[adjv][1]);
            }

        }


        visited[v][0]=2;
        return visited[v][1];

    }

    int  topological_sort(vector<vector<int>>&adjl)
    {
        int N=adjl.size();
        vector<vector<int>>visited(N,vector<int>(2,0));

        int ans=0;
        for(int i=1;i<N;i++)
        {
            if(visited[i][0]==0)
            {   int cur=0;
                int curr_d=dfs(i,adjl,visited);

                if(curr_d==-1)
                return -1;

                ans=max(ans,curr_d);
            }
        }

        return ans;
    }

    int minimumSemesters(int n, vector<vector<int>>& relations)
    {


     vector<int>inCount(n+1,0);

     vector<vector<int>>graph(n+1);


     for(auto& relation:relations)
     {
        graph[relation[0]].push_back(relation[1]);
        inCount[relation[1]]++;
     }


     int step=0;
     int studiedCount=0;



     vector<int>bfsQueue;


     for(int node=1;node<n+1;node++)
     {
        if(inCount[node]==0)
        bfsQueue.push_back(node);
     }

     // Start learning with BFS

     while(!bfsQueue.empty())
     {
         // start new semester
         step++;

         vector<int>nextQueue;
         for(auto& node:bfsQueue)
         {
              studiedCount++;
              for(auto& endNode:graph[node])
              {
                inCount[endNode]--;

                // if all prerequisite courses learned
                if(inCount[endNode]==0)
                nextQueue.push_back(endNode);

              }
         }

         bfsQueue=nextQueue;

     }

     // check if learn all courses

     return studiedCount==n?step:-1;



    }
};
/////////////////////