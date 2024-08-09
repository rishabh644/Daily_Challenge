class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {


        vector<vector<int>>ans;
        int x=rStart,y=cStart;

        int dx=0,dy=1;// Initial direction (moving right)
        int steps=1;
        int totalSteps=rows*cols;

        ans.push_back({x,y});


        while(ans.size()<totalSteps)
        {
           for(int i=0;i<2;++i)
           {
               for(int j=0;j<steps;++j)
               {
                  x+=dx;
                  y+=dy;

                  if(x>=0 && x<rows && y>=0 && y<cols)
                  {
                    ans.push_back({x,y});
                  }

               }
               swap(dx,dy);
               dy=-dy;
           }
           // Change direction: right->down->left->up
           steps++;
        }

        return ans;
    }
};