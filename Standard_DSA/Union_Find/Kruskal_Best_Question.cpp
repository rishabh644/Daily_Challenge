
class Identity{
      private:
      vector<int>P;
      vector<int>R;
      public:
      Identity(int sz)
      {

        P.resize(sz);
        R.resize(sz);

        for(int i=0;i<sz;i++)
        {
            P[i]=i;
            R[i]=0;
        }

      }

      int find(int nd)
      {
          if(P[nd]==nd)
          return nd;

          int pr=find(P[nd]);
          P[nd]=pr;
          return pr;

      }

      bool check(int x,int y)
      {
         if(find(x)==find(y))
         return true;
         else
         return false;
      }

      void union_(int x,int y)
      {
          int px=find(x);
          int py=find(y);

         if(R[px]<R[py])
         {
            P[px]=py;
         }
         else if(R[px]>R[py])
         {
            P[py]=px;
         }
         else
         {
            P[px]=py;
            R[py]+=1;
         }

      }

};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n)
    {
        Identity obj(n);

        sort(logs.begin(),logs.end());

        int cnt=0;

        for(auto e:logs)
        {
            int t=e[0];
            int x=e[1];
            int y=e[2];

            if(!obj.check(x,y))
            {
                obj.union_(x,y);
                cnt+=1;
            }
            if(cnt==n-1)
            return t;
        }

        return -1;

    }
};

//////////
class Identity {
private:
    vector<int> P;
    vector<int> S;

public:
    Identity(int sz) {
        P.resize(sz);
        S.resize(sz, 1); // Initialize sizes to 1

        for (int i = 0; i < sz; i++) {
            P[i] = i;
        }
    }

    int find(int nd) {
        if (P[nd] == nd)
            return nd;

        P[nd] = find(P[nd]); // Path compression
        return P[nd];
    }

    void union_(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px != py) {
            if (S[px] < S[py]) {
                P[px] = py;
                S[py] += S[px];
            } else {
                P[py] = px;
                S[px] += S[py];
            }
        }
    }
};
