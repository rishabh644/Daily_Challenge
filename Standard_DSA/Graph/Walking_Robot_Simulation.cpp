class Solution {
public:
    char new_dir(char dr,int rt)
    {
        if(dr=='A')
        {
            if(rt==-1)
            return 'B';
            else
            return 'D';
        }
        else if(dr=='B')
        {
            if(rt==-1)
            return 'C';
            else
            return 'A';
        }
        else if(dr=='C')
        {
            if(rt==-1)
            return 'D';
            else
            return 'B';
        }
        else
        {
            if(rt==-1)
            return 'A';
            else
            return 'C';
        }
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {

       set<pair<int,int>>st;

       for(int i=0;i<obstacles.size();i++)
       {
          st.insert({obstacles[i][0],obstacles[i][1]});
       }

       int ans=0;
       char dir='A';
       int x=0,y=0;

       for(auto cmnd:commands)
       {
           if(cmnd==-1 || cmnd==-2)
           {
              dir=new_dir(dir,cmnd);
           }
           else
           {
               if(dir=='A')
               {

                     int mY=y+cmnd;
                     int mv=y+1;
                     while(mv<=mY)
                     {
                         if(st.find({x,mv})!=st.end())
                         break;

                         y=mv;
                         mv++;
                     }

                     ans=max(ans,x*x+y*y);

               }
               else if(dir=='B')
               {
                     int mX=x+cmnd;
                     int mv=x+1;
                     while(mv<=mX)
                     {
                         if(st.find({mv,y})!=st.end())
                         break;

                         x=mv;
                         mv++;
                     }

                     ans=max(ans,x*x+y*y);
               }
               else if(dir=='C')
               {
                     int mY=y-cmnd;
                     int mv=y-1;
                     while(mv>=mY)
                     {
                         if(st.find({x,mv})!=st.end())
                         break;

                         y=mv;
                         mv--;
                     }

                     ans=max(ans,x*x+y*y);
               }
               else
               {
                     int mX=x-cmnd;
                     int mv=x-1;

                     while(mv>=mX)
                     {
                         if(st.find({mv,y})!=st.end())
                         break;

                         x=mv;
                         mv--;
                     }

                     ans=max(ans,x*x+y*y);
               }
           }

       }

        return ans;
    }
};