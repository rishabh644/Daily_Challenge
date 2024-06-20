class Solution {
public:
    bool isPossible(vector<int>&position,int mid,int m)
    {
        int count=1;

        int last_position=position[0];

        for(int i=1;i<position.size();i++)
        {
            if( (position[i]-last_position)>=mid )
            {
                count++;
                last_position=position[i];
            }
            if(count>=m)
            return true;

        }

        return false;

    }
    int maxDistance(vector<int>& position, int m)
    {


       sort(position.begin(),position.end());
       int n=position.size();

       int lf=1;
       int mf=position.back()-position.front();


       int ans=lf;

       while(lf<=mf)
       {
          int mid=(lf+mf)/2;

          if(isPossible(position,mid,m))
          {
            ans=mid;
            lf=mid+1;
          }
          else{
            mf=mid-1;
          }

       }

       return ans;

    }
};