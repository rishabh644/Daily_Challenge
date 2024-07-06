int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

      int ts=0;



      int n=grumpy.size();

      for(int i=0;i<n;i++)
      {
        if(grumpy[i]==0)
        {
            ts+=customers[i];
        }

      }

      int ans=ts;
      int ct=0;
      for(int i=0;i<minutes;i++)
      {
           if(grumpy[i]==1)
           {
            ct+=customers[i];
           }

      }
      ans=max(ans,ts+ct);
      for(int i=minutes;i<n;i++)
      {
          if(grumpy[i-minutes]==1)
          ct-=customers[i-minutes];
          if(grumpy[i]==1)
          ct+=customers[i];

          ans=max(ans,ts+ct);

      }

      return ans;

    }
};