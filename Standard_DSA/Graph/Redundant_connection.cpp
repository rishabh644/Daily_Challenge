class Disjointset
{   private:
    vector<int>arr;
    vector<int>asize;
    public:
    Disjointset(int n)
    {

        arr.resize(n+1);
        asize.resize(n+1);

        for(int i=1;i<=n;i++)
        {
            arr[i]=i;
            asize[i]=1;
        }

    }

    int parent(int nd)
    {
         int pr=arr[nd];

         if(pr!=nd)
         {
            int prpr=parent(pr);
            arr[nd]=prpr;
         }

         return arr[nd];
    }

    void add(int x,int y)
    {
        int px=parent(x);
        int py=parent(y);

        int szx=asize[px];
        int szy=asize[py];

        if(szx<szy)
        {
            arr[px]=py;
            asize[py]+=asize[px];
        }
        else
        {
            arr[py]=px;
            asize[px]+=asize[py];
        }

    }

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       int nodes=edges.size();

       Disjointset obj(nodes);


       for(auto e:edges)
       {

         int e0=e[0];
         int e1=e[1];

         if(obj.parent(e0)!=obj.parent(e1))
         {
            obj.add(e0,e1);
         }
         else
         {
            return {e0,e1};
         }


       }


       return {-1,-1};

    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
