class Solution {
public:
    int findCenter(vector<vector<int>>& edges)
    {
           int ne=edges.size();

           int nv=ne+1;

           int N=nv+1;


           vector<vector<int>>vec(N);

           for(int e=0;e<edges.size();e++)
           {
               vec[edges[e][0]].push_back(edges[e][1]);
               vec[edges[e][1]].push_back(edges[e][0]);
           }

           for(int i=1;i<=nv;i++)
           {

               if(vec[i].size()==nv-1)
               return i;


           }

           return -1;
    }
};