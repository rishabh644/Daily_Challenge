class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths)
    {

          vector<vector<int>>adjl(n+1);

          for(auto e:paths)
          {

            adjl[e[0]].push_back(e[1]);
            adjl[e[1]].push_back(e[0]);

          }

          vector<int>color(n,-1);

          for(int i=1;i<=n;i++)
          {
              unordered_set<int>ngc;
              for(auto ng:adjl[i])
              {
                  if(color[ng-1]!=-1)
                  ngc.insert(color[ng-1]);
              }

              for(int c=1;c<=4;c++)
              {
                if(ngc.find(c)==ngc.end())
                {
                    color[i-1]=c;
                }
              }

          }

          return color;

    }
};